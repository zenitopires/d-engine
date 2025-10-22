## d-engine
d-engine is going to be a rendering engine written almost purely in C. Why? Because I like the simplicity of C and wanted to try something different than C++ for writing a rendering engine.

The aim of this project is to first get the engine to a state where I can draw 2D shapes (it can already do this if you run the project) and later on 3D shapes.

## How to Run it
So far I've tested this only on macOS that supports OpenGL 4.1, so ymmv on other operating systems, but the general build steps would be like this:
1. In the root directory of d-engine, run `cmake .` to download all the required libraries (just SDL at the moment).
2. Run `cmake --build .` to build the executable `d-test`.
3. Run `./d-test`. You should see a blue rectangle drawn on your screen.
