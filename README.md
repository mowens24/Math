# Math Visualizer

A modern C++17 OpenGL application for visualizing mathematical equations and graphs, featuring a real-time GUI powered by ImGui. Built with modular architecture and leveraging popular open-source libraries.

## Features

- **Equation Input:** Enter and evaluate mathematical expressions with variable support.
- **Graph Plotting:** Visualize equations as graphs with adjustable parameters.
- **Real-Time GUI:** Interactive controls using ImGui.
- **OpenGL Rendering:** Efficient rendering pipeline using GLFW and GLAD.
- **Expression Parsing:** Powered by muparser and exprtk for flexible math evaluation.
- **Cross-Platform:** CMake-based build system for Windows, macOS, and Linux.


## Build Instructions

1. **Clone the repository:**
   ```sh
   git clone --recurse-submodules https://github.com/yourusername/math-visualizer.git
   cd math-visualizer
   ```

2. **Install dependencies:**
   - CMake >= 3.10
   - A C++17 compiler
   - OpenGL development libraries
   - [GLFW](https://www.glfw.org/), [GLAD](https://glad.dav1d.de/), [ImGui](https://github.com/ocornut/imgui), [muparser](https://beltoforion.de/en/muparser/), [exprtk](https://github.com/ArashPartow/exprtk)

3. **Build the project:**
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```

4. **Run the application:**
   ```sh
   ./bin/MyProjectApp
   ```

## Project Structure

```
.
├── include/         # Project headers
├── src/             # Source files
├── shaders/         # GLSL shaders
├── third_party/     # External libraries
├── build/           # Build output
├── CMakeLists.txt   # Build configuration
└── README.md
```

## License

This project is licensed under the MIT License.

## Credits

- [GLFW](https://www.glfw.org/)
- [GLAD](https://glad.dav1d.de/)
- [ImGui](https://github.com/ocornut/imgui)
- [muparser](https://beltoforion.de/en/muparser/)
- [exprtk](https://github.com/ArashPartow/exprtk)

---


