# Firefly Game Engine
Firefly is a cross-platform game engine built with C++ using GLFW.


## Development Roadmap

### Setup
- [x] Setup C++ project  
- [x] Create custom `bin/` path for intermediate files 
- [x] Create dynamic linking with GLFW library  
- [x] Integrate static GLEW library for future support for GLFW  
- [ ] Add `.gitignore` to remove OS-specific binaries

### Window
- [x] Add `window.h` class definitions 
- [x] Add `window.cpp` implementation 
- [x] Add `firefly::graphics::Window` test in `main.cpp`
- [x] Add key press and mouse press events
- [x] Add dynamic mouse and key location fetching
- [x] Link key, mouse, and cursor position callbacks to GLFW superwindow
- [x] Add debugging mechanism to detect OpenGL errors
- [ ] Create unit testing for `firefly::graphics::Window`

### GLEW
- [x] Init `glew` inside `header.cpp` to allow future library utils

## Math
- [x] Create `vec2`, `vec3` and `vec4` objects with basic operations
- [x] Create `math.h` header for math library 
- [x] Develop `mat4.h` for 4x4 matrices and define common operations
- [x] Add union data management to extract matrix column easily
- [x] Add common math functions in `math_func.h`
- [ ] Add unit testing for math library 
- [ ] Add epsilon floating point comparison for equality or inequality operations

## Shaders
- [x] Add `shader.h` class definition and implementation
- [x] Create basic test frags and verts for gradient
- [x] Test visual matrix rotation and transformation
- [ ] Create unit testing environment for `firefly::graphics::Shader`

## Buffers
- [x] Create `buffer.h`, `arraybuffer.h` and `vertexarray.h` for rendering engine
- [x] Test with gradient implementation

## Renderers
- [x] Create `Renderable.h` superclass for future renderable type prototype
- [x] Create simple 2D renderer class
