# src/CmakeLists.txt
set(SRC_FILES
    main.cpp
    Application.cpp
    Renderer.cpp
    ImGuiLayer.cpp
    # Add more source files here
)


add_executable(MyProjectApp ${SRC_FILES})

target_include_directories(MyProjectApp 
    PRIVATE 
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/vendor
        ${CMAKE_SOURCE_DIR}/vendor/imgui
        ${CMAKE_SOURCE_DIR}/vendor/glad/include
        ${CMAKE_SOURCE_DIR}/vendor/glfw/include
        ${CMAKE_SOURCE_DIR}/vendor/glm
        ${CMAKE_SOURCE_DIR}/vendor/stb
        ${CMAKE_SOURCE_DIR}/third_party/muparser/include
)


# Link libraries:
target_link_libraries(MyProjectApp
    PRIVATE
        muparser
        glm
        glfw
        glad
        imgui
        -framework OpenGL
)


# Shaders

file(COPY ${CMAKE_SOURCE_DIR}/shaders 
    DESTINATION ${CMAKE_BINARY_DIR})
