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
- [ ] Create unit testing for `firefly::graphics::Window`

### GLEW
- [x] Init `glew` inside `header.cpp` to allow future library utils

## Math
- [x] Create `vec2`, `vec3` and `vec4` objects with basic operations
- [x] Create `math.h` header for math library 
- [ ] Add unit testing for math library 
- [ ] Add epsilon floating point comparison for equality or inequality operations
