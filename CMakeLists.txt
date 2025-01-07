# Math/CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(MyProjectApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Add third-party libraries
add_subdirectory(third_party/glfw)
add_subdirectory(third_party/glad)
add_subdirectory(third_party/glm)      # Add GLM submodule
add_subdirectory(third_party/muparser)
add_subdirectory(third_party/imgui)

# Add your source code
add_subdirectory(src)

# (Optional) Silence Apple’s deprecation warnings about GLUT / OpenGL
add_definitions(-DGL_SILENCE_DEPRECATION)
