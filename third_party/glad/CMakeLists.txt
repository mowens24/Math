# third_party/glad/CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(glad LANGUAGES C CXX)

add_library(glad STATIC ../../src/glad.c)

target_include_directories(glad PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Define preprocessor definitions if necessary
# target_compile_definitions(glad PUBLIC ... )
