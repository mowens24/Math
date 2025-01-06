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
        ${CMAKE_SOURCE_DIR}/third_party
        ${CMAKE_SOURCE_DIR}/third_party/imgui
        ${CMAKE_SOURCE_DIR}/third_party/glad
        ${CMAKE_SOURCE_DIR}/third_party/glfw
        ${CMAKE_SOURCE_DIR}/third_party/glm
        ${CMAKE_SOURCE_DIR}/third_party/stb
        ${CMAKE_SOURCE_DIR}/third_party/muparser/
)


# Link libraries:
target_link_libraries(MyProjectApp
    PRIVATE
        muparser
        glm
        glfw
        glad
        imgui
        
)


# Shaders

file(COPY ${CMAKE_SOURCE_DIR}/shaders 
    DESTINATION ${CMAKE_BINARY_DIR})
