# Docker

Build pokeemerald-platinum without installing the toolchain on your host machine.

## Prerequisites

- [Docker](https://docs.docker.com/get-docker/) with Compose v2

## Usage

```bash
# Build the ROM
make docker-build

# Open a shell inside the build environment
make docker-shell

# Remove the build + ccache volumes (full reset)
make docker-clean
```

The finished ROM is written to `dist/pokeemerald.gba`.

## How it works

The container is an Ubuntu 24.04 image with the ARM cross-compilation toolchain (`gcc-arm-none-eabi`, `binutils-arm-none-eabi`) and build dependencies pre-installed. On first run Docker builds the image; subsequent runs reuse it.

The build is **isolated from your host working tree** so it never touches your native build:

- Your repo is mounted **read-only** at `/src`. The container cannot modify your sources, tool binaries, or build artifacts.
- On each build, the sources are `rsync`-ed into a persistent `platinum_build` Docker volume at `/build`, and the compile happens there. The host-OS-specific outputs (`tools/*` binaries, `build/`) stay inside that volume - they are never written to your host `tools/` or `build/` directories.
- Only the finished `pokeemerald.gba` is copied back out, to `dist/` on the host (the one writable host path), and `chown`-ed to your user.
- A persistent `platinum_ccache` volume caches `ccache` data across builds, and the `platinum_build` volume keeps `build/` warm, so recompiles stay incremental.

Because the build never writes to your host `tools/` or `build/`, you can freely alternate between `make` on the host and `make docker-build` without the two clobbering each other.

If you want a completely fresh build (e.g. to reclaim disk or after a toolchain change), run `make docker-clean` to drop the `platinum_build` and `platinum_ccache` volumes; the next `make docker-build` repopulates them.
