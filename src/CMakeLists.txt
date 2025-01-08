# src/CMakeLists.txt

# Define source files
set(SRC_FILES
    main.cpp
    Application.cpp
    Renderer.cpp
    ImGuiLayer.cpp
    # test_openmp.cpp  # Include only if present
)

# Define a static library from source files
add_library(MyProjectLib STATIC ${SRC_FILES})

# Include directories specific to this library
target_include_directories(MyProjectLib PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/glfw/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/glm/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/muparser/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/glad/include
)

# Link libraries to this library
target_link_libraries(MyProjectLib PUBLIC 
    glfw
    glm
    muparser
    imgui
    OpenGL::GL
    OpenMP::OpenMP_CXX
)

# Apply OpenMP Settings
if(OpenMP_CXX_FOUND)
    target_compile_options(MyProjectLib PUBLIC ${OpenMP_CXX_FLAGS})
    target_link_libraries(MyProjectLib PUBLIC OpenMP::OpenMP_CXX)
endif()

# Copy Shaders
file(COPY ${CMAKE_SOURCE_DIR}/shaders 
    DESTINATION ${CMAKE_BINARY_DIR})
