# MyProject/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(MyProjectApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# subdirectories:
add_subdirectory(src)
add_subdirectory(third_party/glfw)
add_subdirectory(third_party/glad)
add_subdirectory(third_party/imgui)
add_subdirectory(third_party/glm)
add_definitions(-DGL_SILENCE_DEPRECATION)

