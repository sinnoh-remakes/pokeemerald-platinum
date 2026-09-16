import tkinter as tk
from tkinter import messagebox
from tkinter import filedialog
from PIL import Image, ImageTk, ImageEnhance
import json
import os

DEFAULT_TOP_TILE_ID = 575
MAX_SIZE = 100
BORDER_W = 7
BORDER_H = 5
BG_ALPHA = 0.8

def id_to_color(num):
    return f"#{(num * 123457) & 0xFFFFFF:06x}"


class TilePainter:
    def __init__(self, root):
        self.root = root
        self.root.title("Overlay Tile Painter")

        self.play_w = 20
        self.play_h = 20

        self.bg_image_path = None
        self.bg_image_tk = None

        self.initial_eva = 8
        self.initial_evb = 8
        self.layout = ""
        self.map_name = ""

        self.primary_tileset = None
        self.secondary_tileset = None
        self.flat_metatiles = []

        self.tile_size = 20
        self.current_tile_id = DEFAULT_TOP_TILE_ID

        self.tiles = {}
        self.tk_cache = {}

        self.controls_frame = tk.Frame(self.root)
        self.controls_frame.pack(side=tk.TOP, fill=tk.X)
        self.create_controls() 

        self.main_area = tk.Frame(self.root)
        self.main_area.pack(side=tk.TOP, fill=tk.BOTH, expand=True)

        self.create_canvas() 
        self.create_palette()

        self.draw_grid()



    # ------------------------------
    def create_controls(self):
        frame = tk.Frame(self.root)
        frame.pack()

        tk.Label(frame, text="W:").pack(side=tk.LEFT)
        self.w_entry = tk.Entry(frame, width=4)
        self.w_entry.insert(0, "20")
        self.w_entry.pack(side=tk.LEFT)

        tk.Label(frame, text="H:").pack(side=tk.LEFT)
        self.h_entry = tk.Entry(frame, width=4)
        self.h_entry.insert(0, "20")
        self.h_entry.pack(side=tk.LEFT)

        tk.Button(frame, text="Apply", command=self.update_size).pack(side=tk.LEFT)

        tk.Label(frame, text="Tile Num:").pack(side=tk.LEFT)
        self.tile_entry = tk.Entry(frame, width=6)
        self.tile_entry.insert(0, str(self.current_tile_id))
        self.tile_entry.pack(side=tk.LEFT)

        # Shift buttons
        tk.Button(frame, text="↑", command=lambda: self.shift(0, -1)).pack(side=tk.LEFT)
        tk.Button(frame, text="↓", command=lambda: self.shift(0, 1)).pack(side=tk.LEFT)
        tk.Button(frame, text="←", command=lambda: self.shift(-1, 0)).pack(side=tk.LEFT)
        tk.Button(frame, text="→", command=lambda: self.shift(1, 0)).pack(side=tk.LEFT)

        tk.Button(frame, text="Open map.json", command=self.load_json).pack(side=tk.LEFT)
        tk.Button(frame, text="Copy JSON", command=self.copy_json).pack(side=tk.LEFT)

        # --- Background opacity slider ---
        tk.Label(frame, text="Alpha").pack(side=tk.LEFT, padx=(10, 2))

        self.bg_opacity = tk.DoubleVar(value=BG_ALPHA)
        slider = tk.Scale(
            frame,
            from_=0.0,
            to=1.0,
            resolution=0.01,
            orient=tk.HORIZONTAL,
            variable=self.bg_opacity,
            command=self.on_bg_opacity_change,
            length=120
        )
        slider.pack(side=tk.LEFT)


    # ------------------------------
    def create_canvas(self):
        self.canvas = tk.Canvas(self.main_area, bg="black")
        self.canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        self.canvas.bind("<Button-1>", self.paint_tile)   # LEFT = paint
        self.canvas.bind("<Button-3>", self.erase_tile)   # RIGHT = erase

    # ------------------------------
    @property
    def full_w(self):
        return self.play_w + BORDER_W * 2

    @property
    def full_h(self):
        return self.play_h + BORDER_H * 2

    # ------------------------------
    def paint_tile(self, ev):
        self.update_tile_id()
        x = ev.x // self.tile_size
        y = ev.y // self.tile_size
        if 0 <= x < self.full_w and 0 <= y < self.full_h:
            self.tiles[(x, y)] = self.current_tile_id
            self.redraw()

    # ------------------------------
    def erase_tile(self, ev):
        x = ev.x // self.tile_size
        y = ev.y // self.tile_size
        if (x, y) in self.tiles:
            del self.tiles[(x, y)]
            self.redraw()

    # ------------------------------
    def shift(self, dx, dy):
        shifted = {}
        for (x, y), val in self.tiles.items():
            shifted[(x + dx, y + dy)] = val
        self.tiles = shifted
        self.redraw()

    # ------------------------------
    def update_size(self):
        try:
            w = int(self.w_entry.get())
            h = int(self.h_entry.get())
            if 1 <= w <= MAX_SIZE and 1 <= h <= MAX_SIZE:
                self.play_w = w
                self.play_h = h
                self.redraw()
            else:
                messagebox.showerror("Error", f"Playable size must be 1–{MAX_SIZE}")
        except:
            pass

    # ------------------------------
    def update_tile_id(self):
        try:
            self.current_tile_id = int(self.tile_entry.get())
        except:
            self.current_tile_id = DEFAULT_TOP_TILE_ID

    # ------------------------------
    def draw_grid(self):
        self.canvas.delete("all")

        wpx = self.full_w * self.tile_size
        hpx = self.full_h * self.tile_size

        self.canvas.config(width=wpx, height=hpx)

        # Draw tiles
        for x in range(self.full_w):
            for y in range(self.full_h):
                tid = self.tiles.get((x, y), None)

                px = x * self.tile_size
                py = y * self.tile_size
                x2 = px + self.tile_size
                y2 = py + self.tile_size

                # No tile → draw white rect
                if tid is None:
                    self.canvas.create_rectangle(px, py, x2, y2, fill="white", outline="gray")
                    continue

                #
                # Attempt metatile draw
                #
                if self.flat_metatiles and isinstance(tid, int) and 0 <= tid < len(self.flat_metatiles):
                    tile_img = self.flat_metatiles[tid].resize((self.tile_size, self.tile_size), Image.NEAREST)
                    if tile_img is not None:
                        try:
                            # Convert tile to PhotoImage if needed
                            # Cache per tile ID so you don’t re-wrap each frame
                            if tid not in self.tk_cache:
                                self.tk_cache[tid] = ImageTk.PhotoImage(tile_img)
                            self.canvas.create_image(px, py, image=self.tk_cache[tid], anchor="nw")
                            continue
                        except Exception as e:
                            print("Tile draw ERR:", e)

                #
                # Fallback if out of bounds or missing → color rectangle
                #
                color = id_to_color(tid)
                self.canvas.create_rectangle(px, py, x2, y2, fill=color, outline="gray")


        if self.bg_image_tk:
            self.canvas.create_image(0, 0, image=self.bg_image_tk, anchor="nw")

        # --- Draw border guide lines ---
        xl1 = BORDER_W * self.tile_size
        xl2 = (self.full_w - BORDER_W) * self.tile_size
        yl1 = BORDER_H * self.tile_size
        yl2 = (self.full_h - BORDER_H) * self.tile_size

        # draw lines
        self.canvas.create_line(xl1, 0, xl1, hpx, fill="red", width=2)
        self.canvas.create_line(xl2, 0, xl2, hpx, fill="red", width=2)
        self.canvas.create_line(0, yl1, wpx, yl1, fill="red", width=2)
        self.canvas.create_line(0, yl2, wpx, yl2, fill="red", width=2)

    # ------------------------------
    def redraw(self):
        self.draw_grid()

    # ------------------------------
    # ------------------------------
    def export_json(self):
        overlay = {
            "initial_eva": self.initial_eva,
            "initial_evb": self.initial_evb,
            "tiles": []
        }
        for (x, y), tid in self.tiles.items():
            overlay["tiles"].append({
                "top_tile_id": tid,
                "x": x - BORDER_W,
                "y": y - BORDER_H
            })

        # Generate JSON string for overlay only
        overlay_json = json.dumps(overlay, indent=2)
        # prepend "overlay": to match your format
        return f'  "overlay": {overlay_json}'


    # ------------------------------
    def copy_json(self):
        js = self.export_json()
        self.root.clipboard_clear()
        self.root.clipboard_append(js)
        messagebox.showinfo("Copied", "JSON copied to clipboard!")

    #-------------------------------

    def load_json(self):
        # Determine initial directory
        script_dir = os.path.dirname(os.path.abspath(__file__))
        preferred_dir = os.path.abspath(os.path.join(script_dir, "../../data/maps"))

        if os.path.exists(preferred_dir):
            initial_dir = preferred_dir
        else:
            initial_dir = script_dir

        path = filedialog.askopenfilename(
            initialdir=initial_dir,
            filetypes=[("JSON Files", "*.json"), ("All Files", "*.*")]
        )

        if not path:
            return

        try:
            with open(path, "r") as f:
                data = json.load(f)
        except Exception as e:
            messagebox.showerror("Error", f"Failed to load JSON:\n{e}")
            return

        # Layout stored at top level
        if "layout" in data:
            self.layout = data["layout"]

        if "name" in data:
            self.map_name = data["name"]

        # Overlay exists?
        ov = data.get("overlay")
        if ov:
            self.initial_eva = ov.get("initial_eva", self.initial_eva)
            self.initial_evb = ov.get("initial_evb", self.initial_evb)

            # Wipe existing tiles
            self.tiles = {}

            # Paint tiles from JSON
            for t in ov.get("tiles", []):
                x = t.get("x") + BORDER_W
                y = t.get("y") + BORDER_H
                tid = t.get("top_tile_id", DEFAULT_TOP_TILE_ID)
                self.current_tile_id
                if x is not None and y is not None:
                    self.tiles[(x, y)] = tid

        self.load_layout_info(path)
        self.load_map_background()
        self.redraw()
        messagebox.showinfo("Loaded", "Map JSON loaded successfully!")

    #---------------------------

    def load_map_background(self):
        if not self.map_name:
            return

        # directory next to script
        script_dir = os.path.dirname(os.path.abspath(__file__))
        img_dir = os.path.join(script_dir, "map_images")
        img_path = os.path.join(img_dir, f"{self.map_name}.png")

        if os.path.exists(img_path):
            print("BG found")
            self.bg_image_path = img_path
            self.update_bg_image()
        else:
            print("No BG found")
            self.bg_image_path = None
            self.bg_image_tk = None

    #---------------------------

    def update_bg_image(self):
        if not self.bg_image_path:
            self.bg_image_tk = None
            return

        try:
            img = Image.open(self.bg_image_path)

            # Full tile area incl. border
            wpx = self.full_w * self.tile_size
            hpx = self.full_h * self.tile_size
            img = img.resize((wpx, hpx), Image.NEAREST)

            alpha = float(BG_ALPHA) 
            if img.mode != "RGBA":
                img = img.convert("RGBA")

            a = img.split()[3]
            a = ImageEnhance.Brightness(a).enhance(alpha)
            img.putalpha(a)

            self.bg_image_tk = ImageTk.PhotoImage(img)

        except Exception as e:
            print("BG load error:", e)
            self.bg_image_tk = None

    #---------------------------

    def load_layout_info(self, map_json_path):
        if not hasattr(self, "layout") or not self.layout:
            print("No layout string in map.json; skipping layout load")
            return

        # Determine path to layouts.json
        map_dir = os.path.dirname(os.path.abspath(map_json_path))
        layouts_path = os.path.abspath(os.path.join(map_dir, "../../layouts/layouts.json"))

        print("Looking for layouts.json at:", layouts_path)
        if not os.path.exists(layouts_path):
            print("layouts.json not found; skipping")
            return

        try:
            with open(layouts_path, "r") as f:
                layout_data = json.load(f)
        except Exception as e:
            print("Failed to read layouts.json:", e)
            return

        layouts = layout_data.get("layouts", [])
        match = None

        for entry in layouts:
            if entry.get("id") == self.layout:
                match = entry
                break

        if not match:
            print("No matching layout id found in layouts.json:", self.layout)
            return

        # Found matching entry
        print("Found matching layout:", self.layout)

        map_w = match.get("width")
        map_h = match.get("height")

        if isinstance(map_w, int) and isinstance(map_h, int):
            self.play_w = map_w
            self.play_h = map_h
            print("Setting grid to:", map_w, map_h)

            try:
                self.w_entry.delete(0, tk.END)
                self.w_entry.insert(0, str(map_w))

                self.h_entry.delete(0, tk.END)
                self.h_entry.insert(0, str(map_h))
            except Exception as e:
                print("Failed updating entry widgets:", e)

        self.primary_tileset = match.get("primary_tileset")
        self.secondary_tileset = match.get("secondary_tileset")

        self.load_metatile_images()

        print("primary_tileset:", self.primary_tileset)
        print("secondary_tileset:", self.secondary_tileset)

    # ------------------------------

    def load_metatile_images(self):
        """
        Attempts to load primary + secondary metatile PNGs from ./meta_tile_images.
        If both present → validates + slices → creates 16x16 tiles.
        If only one present → shows error + aborts loading.
        If neither present → silently ignore (no metatiles).
        """
        if not hasattr(self, "primary_tileset") or not hasattr(self, "secondary_tileset"):
            return  # nothing to load

        script_dir = os.path.dirname(os.path.abspath(__file__))
        meta_dir = os.path.join(script_dir, "meta_tile_images")

        p_name = f"{self.primary_tileset}_Metatiles.png"
        s_name = f"{self.secondary_tileset}_Metatiles.png"
        p_path = os.path.join(meta_dir, p_name)
        s_path = os.path.join(meta_dir, s_name)

        p_exists = os.path.exists(p_path)
        s_exists = os.path.exists(s_path)

        # --- Case: neither exists
        if not p_exists and not s_exists:
            print("No metatile images found; skipping tile slicing.")
            self.metatile_images = None
            self.metatile_list = None
            return

        # --- Case: only one exists → error
        if p_exists and not s_exists:
            messagebox.showerror(
                "Tileset Missing",
                f"Missing metatile image:\n{s_name}"
            )
            self.metatile_images = None
            self.metatile_list = None
            return

        if s_exists and not p_exists:
            messagebox.showerror(
                "Tileset Missing",
                f"Missing metatile image:\n{p_name}"
            )
            self.metatile_images = None
            self.metatile_list = None
            return

        # --- Case: BOTH exist → load + slice
        try:
            primary_img  = Image.open(p_path)
            secondary_img = Image.open(s_path)

            primary_tiles = self._slice_metatile_sheet(primary_img)
            secondary_tiles = self._slice_metatile_sheet(secondary_img)

            if primary_tiles is None or secondary_tiles is None:
                # Error already displayed inside slice fn
                self.metatile_images = None
                self.metatile_list = None
                return

            # Store structured tiles
            self.metatile_images = {
                "primary":  primary_tiles,
                "secondary": secondary_tiles
            }

            # Also flatten list if needed later
            self.metatile_list = []
            for row in primary_tiles:
                self.metatile_list.extend(row)
            for row in secondary_tiles:
                self.metatile_list.extend(row)

            print("Metatile images successfully loaded + sliced.")

        except Exception as e:
            print("Error loading metatile base images:", e)
            self.metatile_images = None
            self.metatile_list = None

        # Flatten tiles into a single list
        self.flat_metatiles = []
        for row in self.metatile_images.get("primary", []):
            self.flat_metatiles.extend(row)
        for row in self.metatile_images.get("secondary", []):
            self.flat_metatiles.extend(row)

        self.rebuild_palette()


    # ------------------------------

    def _slice_metatile_sheet(self, img):
        """
        Scale image width to 128px (nearest neighbor),
        verify height divisible by 16,
        slice into 16×16 tiles → return list[row][col].
        """

        # Force RGBA
        if img.mode != "RGBA":
            img = img.convert("RGBA")

        orig_w, orig_h = img.size

        # --- scale width → 128px
        target_w = 128
        scale_factor = target_w / orig_w
        new_h = int(orig_h * scale_factor)

        img = img.resize((target_w, new_h), Image.NEAREST)
        w, h = img.size

        # Height must divide into 16px rows
        if h % 16 != 0:
            messagebox.showerror(
                "Metatile Error",
                f"Metatile sheet has invalid height {h}px (must be divisible by 16)."
            )
            return None

        rows = h // 16
        cols = 8   # always

        tiles = []
        for r in range(rows):
            row_tiles = []
            for c in range(cols):
                x0 = c * 16
                y0 = r * 16
                tile = img.crop((x0, y0, x0 + 16, y0 + 16))
                row_tiles.append(tile)
            tiles.append(row_tiles)

        return tiles

    # ------------------------------

    def on_bg_opacity_change(self, value):
        global BG_ALPHA
        try:
            BG_ALPHA = float(value)
        except:
            BG_ALPHA = 0.5

        # Reload the image with new opacity
        if self.bg_image_path:
            self.update_bg_image()
            self.redraw()

    # ------------------------------

    def create_palette(self):
        # Right-side scrollable palette frame
        palette_frame = tk.Frame(self.main_area)
        palette_frame.pack(side=tk.RIGHT, fill=tk.Y)

        # Scrollbar
        scrollbar = tk.Scrollbar(palette_frame, orient=tk.VERTICAL)
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y)

        # Canvas that will scroll
        self.palette_canvas = tk.Canvas(
            palette_frame,
            width=218,
            height=500,
            yscrollcommand=scrollbar.set
        )
        self.palette_canvas.pack(side=tk.LEFT, fill=tk.Y)

        scrollbar.config(command=self.palette_canvas.yview)

        # Inner frame where tile buttons will appear
        self.palette_inner = tk.Frame(self.palette_canvas)
        self.palette_window = self.palette_canvas.create_window(
            (0, 0),
            window=self.palette_inner,
            anchor="nw"
        )

        # When resized, fix scroll area
        self.palette_inner.bind(
            "<Configure>",
            lambda e: self.palette_canvas.configure(
                scrollregion=self.palette_canvas.bbox("all")
            )
        )

        self.palette_tiles = []     # PhotoImages to keep references
        self.palette_buttons = []   # Buttons / labels representing tiles
        self.selected_palette_idx = None

    # ------------------------------

    def rebuild_palette(self):
        # Remove old palette items
        for widget in self.palette_inner.winfo_children():
            widget.destroy()

        self.palette_tiles.clear()
        self.palette_buttons.clear()
        self.selected_palette_idx = None

        if not self.flat_metatiles:
            return

        TILE_DISPLAY_SIZE = self.tile_size  # match drawing size

        for i, img in enumerate(self.flat_metatiles):
            # scale for display
            thumb = img.resize((TILE_DISPLAY_SIZE, TILE_DISPLAY_SIZE), Image.NEAREST)
            tkimg = ImageTk.PhotoImage(thumb)
            self.palette_tiles.append(tkimg)

            lbl = tk.Label(
                self.palette_inner,
                image=tkimg,
                bd=2,
                relief="flat"
            )

            lbl.grid(row=i // 8, column=i % 8, padx=2, pady=2)  # 8 columns
            lbl.bind("<Button-1>", lambda e, idx=i: self.select_palette_tile(idx))

            self.palette_buttons.append(lbl)

    # ------------------------------

    def select_palette_tile(self, idx):
        # Update selected tile
        self.current_tile_id = idx

        # Update tile entry field
        self.tile_entry.delete(0, tk.END)
        self.tile_entry.insert(0, str(idx))

        # Update border highlighting
        if self.selected_palette_idx is not None:
            old = self.palette_buttons[self.selected_palette_idx]
            old.config(relief="flat", bd=2)

        btn = self.palette_buttons[idx]
        btn.config(relief="solid", bd=2)

        self.selected_palette_idx = idx






# ------------------------------
if __name__ == "__main__":
    root = tk.Tk()
    app = TilePainter(root)
    root.mainloop()
