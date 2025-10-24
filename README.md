## d-engine
d-engine is going to be a rendering engine written almost purely in C. Why? Because I like the simplicity of C and wanted to try something different than C++ for writing a rendering engine. For this project I'm using [C23](https://en.cppreference.com/w/c/23.html).

# Yet Another Rendering Engine, Why?
The reason for building another rendering engine despite there being countless others is two-fold
1. I want to know how game engines/modeling/animation software work and I thought this would be a good way to learn how they at least do the rendering portion of it.
2. I've always been interested in the graphic backends that have powered games that I grew up playing like Half Life, Portal, DOOM, and Halo, to name a few. I'd get lost in those games, exploring the levels, trying to find easter eggs. I'd like to recreate that feeling.

# How?
The aim of this project is to first get the engine to a state where I can draw 2D shapes (it can already do this if you run the project), later on... 3D shapes, and all the other bells and whistles that come with a rendering engine such as model loading, lighting, etc.

## How to Run it
So far I've tested this only on macOS that supports OpenGL 4.1, so ymmv on other operating systems, but the general build steps would be like this:
1. In the root directory of d-engine, run the following command (I'm using the latest version clang (21.1.3) installed through via homebrew so that I can take advantage of C23).
```
cmake -DCMAKE_C_COMPILER=$(brew --prefix llvm)/bin/clang -S . -B build
```
2. Then to build the executable
```
cmake --build build
```
3. Finally run the program
```
./build/app
```
If all goes well. You should see a blue rectangle drawn on your screen.

# Libraries
Check out the dependencies of the project [here](docs/libraries.md).
