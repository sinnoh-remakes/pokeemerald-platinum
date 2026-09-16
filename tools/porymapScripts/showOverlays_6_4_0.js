const LIGHT_LAYER = 0;
let currentMapPath = null;
let lightingPaintMode = false;

function reloadLightingOverlay() {
    if (!currentMapPath) return;

    let resp = utility.readTextFile(currentMapPath);
    if (resp.error) return;

    let mapJson;
    try {
        mapJson = JSON.parse(resp.content);
    } catch (e) {
        return;
    }

    overlay.clear();

    if (mapJson.overlay && Array.isArray(mapJson.overlay.tiles)) {
        for (const t of mapJson.overlay.tiles) {
            if (t.top_tile_id == null || t.x == null || t.y == null) continue;

            const metatileId = t.top_tile_id;
            const tilesPerMetatile = constants.tiles_per_metatile;

            const topIndices = tilesPerMetatile === 8 ? [4,5,6,7] : [8,9,10,11];

            for (let i = 0; i < topIndices.length; i++) {
                const idx = topIndices[i];
                const tileInfo = map.getMetatileTile(metatileId, idx);
                if (!tileInfo) continue;

                const px = t.x * 16 + (i % 2) * 8;
                const py = t.y * 16 + Math.floor(i / 2) * 8;

                overlay.addTileImage(
                    px,
                    py,
                    tileInfo.tileId,
                    tileInfo.xflip,
                    tileInfo.yflip,
                    tileInfo.palette,
                    true,
                    LIGHT_LAYER
                );
            }
        }
    }

    overlay.setOpacity(50, LIGHT_LAYER);
    overlay.show(LIGHT_LAYER);
}

export function onMapOpened(mapName) {
    currentMapPath = `data/maps/${mapName}/map.json`;
    reloadLightingOverlay();
}

export function toggleLightingOverlay() {
    if (overlay.getVisibility(LIGHT_LAYER)) {
        overlay.hide(LIGHT_LAYER);
    } else {
        reloadLightingOverlay();
    }
}

export function toggleLightingPaintMode() {
    lightingPaintMode = !lightingPaintMode;
}

function tileHasPixels(tileId) {
    const pixels = map.getTilePixels(tileId);
    if (!pixels) return false;
    if (Array.isArray(pixels[0])) {
        return pixels.some(row => row.some(pixel => pixel !== 0));
    }
    return pixels.some(pixel => pixel !== 0);
}

function metatileHasTopLayer(metatileId) {
    if (metatileId == null) return false;

    const tilesPerMetatile = constants.tiles_per_metatile;

    if (tilesPerMetatile === 8) {
        return map.getMetatileLayerType(metatileId) !== 1;
    }

    const topTileIndices = [8, 9, 10, 11];
    for (const idx of topTileIndices) {
        const tileInfo = map.getMetatileTile(metatileId, idx);
        if (!tileInfo) continue;
        if (tileHasPixels(tileInfo.tileId)) return true;
    }

    return false;
}


export function onBlockChanged(x, y, prevBlock, newBlock) {
    utility.log(`onBlockChanged called at (${x}, ${y})`);

    if (!lightingPaintMode) {
        return;
    }
    if (!currentMapPath) {
        return;
    }
    if (!newBlock || newBlock.metatileId == null) {
        return;
    }

    const overlayTileId = newBlock.metatileId;

    let resp = utility.readTextFile(currentMapPath);
    if (resp.error) {
        map.setMetatileId(x, y, prevBlock.metatileId);
        return;
    }

    let mapJson;
    try {
        mapJson = JSON.parse(resp.content);
    } catch (e) {
        map.setMetatileId(x, y, prevBlock.metatileId);
        return;
    }

    if (!mapJson.overlay) mapJson.overlay = {};
    if (!Array.isArray(mapJson.overlay.tiles)) mapJson.overlay.tiles = [];

    const existingIndex = mapJson.overlay.tiles.findIndex(
        t => t.x === x && t.y === y
    );

    if (metatileHasTopLayer(overlayTileId)) {
        if (existingIndex >= 0) {
            mapJson.overlay.tiles[existingIndex].top_tile_id = overlayTileId;
        } else {
            mapJson.overlay.tiles.push({
                x: x,
                y: y,
                top_tile_id: overlayTileId
            });
        }
    } else {
        if (existingIndex >= 0) {
            mapJson.overlay.tiles.splice(existingIndex, 1);
        } else {
        }
    }

    utility.writeTextFile(
        currentMapPath,
        JSON.stringify(mapJson, null, 2)
    );

    if (prevBlock && prevBlock.metatileId != null) {
        map.setMetatileId(x, y, prevBlock.metatileId);
    } else {
        map.setMetatileId(x, y, 0);
    }

    reloadLightingOverlay();
}


function shiftOverlayTiles(dx, dy) {
    if (!currentMapPath) return;

    let resp = utility.readTextFile(currentMapPath);
    if (resp.error) return;

    let mapJson;
    try {
        mapJson = JSON.parse(resp.content);
    } catch (e) {
        return;
    }

    if (!mapJson.overlay || !Array.isArray(mapJson.overlay.tiles)) {
        return;
    }

    for (const tile of mapJson.overlay.tiles) {
        tile.x += dx;
        tile.y += dy;
    }

    utility.writeTextFile(currentMapPath,JSON.stringify(mapJson, null, 2));

    reloadLightingOverlay();
}

export function shiftOverlayUp() {
    shiftOverlayTiles(0, -1);
}

export function shiftOverlayDown() {
    shiftOverlayTiles(0, 1);
}

export function shiftOverlayLeft() {
    shiftOverlayTiles(-1, 0);
}

export function shiftOverlayRight() {
    shiftOverlayTiles(1, 0);
}


export function onProjectOpened(projectPath) {
    utility.registerAction("toggleLightingOverlay", "Toggle Lighting", "Shift+O");
    utility.registerToggleAction("toggleLightingPaintMode", "Toggle Lighting Paint Mode", "Shift+L", false);

    utility.registerAction("shiftOverlayUp","Shift Overlay Up","Shift+8");
    utility.registerAction("shiftOverlayDown","Shift Overlay Down","Shift+2");
    utility.registerAction("shiftOverlayLeft","Shift Overlay Left","Shift+4");
    utility.registerAction("shiftOverlayRight","Shift Overlay Right","Shift+6");
}
