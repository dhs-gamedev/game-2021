# game-2021

This is the repository for the Davis Senior High School Gamedev game of the
2021-22 school year.

# Build Instructions

## Dependencies
This project wil be done with OpenGL, and as such has the dependencies of OpenGL
and GLFW. If you are using macOS, the OpenGL component is not required as it
comes with the installation.

GLFW is packaged as a submodule, and it built along with the game, so it is not
necessary to install it separately.

## Build
Checkout the GLFW submodule with
<br>
`git submodule init`
<br>
`git submodule update`.
<br>
Then run
<br>
`./scripts/build.sh`.

## Run
`./scripts/run.sh`
