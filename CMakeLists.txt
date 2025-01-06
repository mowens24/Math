# MyProject/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(MyProjectApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# If you want to use subdirectories:
add_subdirectory(src)
# add_subdirectory(third_party) if needed

add_definitions(-DGL_SILENCE_DEPRECATION)

