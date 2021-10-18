# game-2021

This is the repository for the Davis Senior High School Gamedev game of the
2021-22 school year.

# Build Instructions

## Dependencies
This project will be done with OpenGL, and as such has the dependencies of OpenGL
and GLFW. If you are using macOS, the OpenGL component is not required as it
comes with the installation.

GLFW is packaged as a submodule, and it built along with the game, so it is not
necessary to install it separately.

## Build
Checkout the GLFW submodule with

```bash
git submodule init
git submodule update
```

Then run `./scripts/build.sh` for bash, or `.\scripts\build.bat` for cmd/PowerShell.

## Run
The built game is located under `build/` with the name `game21`. Depending on
your platform, there may be extra folders and/or a suffix after the file name.

## Controls
A key / left arrow key - left
D key / right arrow key - right
Space bar / up arrow key - jump
