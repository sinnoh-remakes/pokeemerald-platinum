const LIGHT_LAYER = 0;

export function addLightingOverlay() {
    const results = utility.getInputText("Overlay JSON", "Paste overlay JSON from map.json:\ne.g \"overlay\": { your_custom_settings }");

    if (results.ok)
    {
        let parsed;
        let text = results.input.trim();

        // If JSON begins with `"overlay":`, wrap automatically
        if (text.startsWith('"overlay"')) {
            text = `{ ${text} }`;
		    try {
		        parsed = JSON.parse(text);
		    } catch (e) {
		        utility.showMessage("Invalid JSON:\n" + e);
		        return;
		    }

            if (!parsed.overlay || !parsed.overlay.tiles) {
                utility.showMessage("JSON missing overlay.tiles");
                return;
            }

            // Clear all first
            overlay.clear();

            for (const t of parsed.overlay.tiles) {
                if (t.top_tile_id == null || t.x == null || t.y == null)
                    continue;

                const px = t.x * 16;
                const py = t.y * 16;
                overlay.addMetatileImage(px, py, t.top_tile_id, true, LIGHT_LAYER);
            }

            // Set opacity (0–100)
            overlay.setOpacity(50, LIGHT_LAYER);

            // Show
            overlay.hide(LIGHT_LAYER);
            showLightingOverlay();

        } else {
			utility.showMessage("Invalid, should start with \"overlay\"");
		}

    }
}

export function showLightingOverlay() {
    if (overlay.getVisibility(LIGHT_LAYER))
    {
        overlay.hide(LIGHT_LAYER);
    }
    else 
    {
        overlay.show(LIGHT_LAYER);
    }
}


// Called when Porymap successfully opens a project.
export function onProjectOpened(projectPath) {
	utility.registerAction("addLightingOverlay", "Set Lighting Tiles", "");
    utility.registerToggleAction("showLightingOverlay", "Toggle Lighting", "", true);
}

// Called when Porymap closes a project. For example, this is called when opening a different project.
export function onProjectClosed(projectPath) {

}

// Called when a map is opened.
export function onMapOpened(mapName) {

}

// Called when a layout is opened, either by selecting a new map/layout in the map list or swapping the layout for the current map.
export function onLayoutOpened(layoutName) {

}

// Called when a block is changed on the map. For example, this is called when a user paints a new tile or changes the collision property of a block.
export function onBlockChanged(x, y, prevBlock, newBlock) {

}

// Called when a border metatile is changed.
export function onBorderMetatileChanged(x, y, prevMetatileId, newMetatileId) {

}

// Called when the mouse enters a new map block.
export function onBlockHoverChanged(x, y) {

}

// Called when the mouse exits the map.
export function onBlockHoverCleared() {

}

// Called when the dimensions of the map are changed.
export function onMapResized(oldWidth, oldHeight, delta) {

}

// Called when the dimensions of the border are changed.
export function onBorderResized(oldWidth, oldHeight, newWidth, newHeight) {

}

// Called when the map is updated by use of the Map Shift tool.
export function onMapShifted(xDelta, yDelta) {

}

// Called when the currently loaded tileset is changed by switching to a new one or by saving changes to it in the Tileset Editor.
export function onTilesetUpdated(tilesetName) {

}

// Called when the selected tab in the main tab bar is changed.
// Tabs are indexed from left to right, starting at 0 (0: Map, 1: Events, 2: Header, 3: Connections, 4: Wild Pokemon).
export function onMainTabChanged(oldTab, newTab) {

}

// Called when the selected tab in the map view tab bar is changed.
// Tabs are indexed from left to right, starting at 0 (0: Metatiles, 1: Collision, 2: Prefabs).
export function onMapViewTabChanged(oldTab, newTab) {

}

// Called when the visibility of the border and connecting maps is toggled on or off.
export function onBorderVisibilityToggled(visible) {

}
