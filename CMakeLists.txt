cmake_minimum_required(VERSION 3.10)
project(MyProjectApp LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)  # or whatever C standard you prefer
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
find_package(OpenGL REQUIRED)
find_package(OpenMP REQUIRED)

add_subdirectory(third_party/glfw)
add_subdirectory(third_party/glad)
add_subdirectory(third_party/imgui)
add_subdirectory(third_party/glm)
add_subdirectory(third_party/muparser)

add_executable(MyProjectApp 
    src/main.cpp 
    src/Application.cpp 
    src/Renderer.cpp 
    src/ImGuiLayer.cpp 
    src/glad.c
)

target_link_libraries(MyProjectApp PUBLIC 
    glfw
    glad
    imgui
    glm
    muparser
    OpenGL::GL
    OpenMP::OpenMP_CXX
)

target_include_directories(MyProjectApp PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(OpenMP_CXX_FOUND)
    target_compile_options(MyProjectApp PUBLIC ${OpenMP_CXX_FLAGS})
    target_link_libraries(MyProjectApp PUBLIC OpenMP::OpenMP_CXX)
endif()

file(COPY ${CMAKE_SOURCE_DIR}/shaders 
     DESTINATION ${CMAKE_BINARY_DIR})
