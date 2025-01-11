// src/Renderer.cpp
#include "../include/MyProject/Renderer.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

namespace MyProject {

// Utility function to load shader source code from a file
std::string LoadShaderSource(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Failed to open shader file: " << filepath << std::endl;
        return "";
    }
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

// Utility function to compile a shader
GLuint CompileShader(GLenum type, const std::string& source) {
    GLuint shader = glCreateShader(type);
    const char* src_cstr = source.c_str();
    glShaderSource(shader, 1, &src_cstr, nullptr);
    glCompileShader(shader);

    // Check for compilation errors
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLint logSize = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logSize);
        std::string infoLog(logSize, ' ');
        glGetShaderInfoLog(shader, logSize, &logSize, &infoLog[0]);
        std::cerr << "Shader Compilation Error:\n" << infoLog << std::endl;
        return 0;
    }
    return shader;
}

// Utility function to create a shader program
GLuint CreateShaderProgram(const std::string& vertexPath, const std::string& fragmentPath) {
    std::string vertexSource = LoadShaderSource(vertexPath);
    std::string fragmentSource = LoadShaderSource(fragmentPath);

    if (vertexSource.empty() || fragmentSource.empty()) {
        std::cerr << "Failed to load shader sources." << std::endl;
        return 0;
    }

    GLuint vertexShader = CompileShader(GL_VERTEX_SHADER, vertexSource);
    if (vertexShader == 0) return 0;

    GLuint fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentSource);
    if (fragmentShader == 0) return 0;

    // Create program and link shaders
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Check for linking errors
    GLint successLink;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &successLink);
    if (!successLink) {
        GLint logSize = 0;
        glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &logSize);
        std::string infoLog(logSize, ' ');
        glGetProgramInfoLog(shaderProgram, logSize, &logSize, &infoLog[0]);
        std::cerr << "Shader Program Linking Error:\n" << infoLog << std::endl;
        return 0;
    }

    // Shaders can be deleted after linking
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

void Renderer::Init()
{
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW." << std::endl;
        return;
    }

    // Set GLFW to use OpenGL 3.3 Core Profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // For macOS
#endif

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "MyProject Window", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLAD before calling any OpenGL function
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD." << std::endl;
        return;
    }

    // Set the viewport
    int width, height;
    glfwGetFramebufferSize(window, &width, &height); // For high-DPI displays
    glViewport(0, 0, width, height);

    // Register a callback for window resize
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* win, int w, int h){
        glViewport(0, 0, w, h);
    });

    // Enable V-Sync
    glfwSwapInterval(1);

    // Build and compile our shader program
    GLuint shaderProgram = CreateShaderProgram("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl");
    if (shaderProgram == 0) {
        std::cerr << "Failed to create shader program." << std::endl;
        return;
    }

    // Set up vertex data (a simple triangle)
    float vertices[] = {
         // Positions         // Colors
         0.0f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f, // Top
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, // Right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f  // Left
    };

    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Bind Vertex Array Object first
    glBindVertexArray(VAO);

    // Bind and set vertex buffer(s)
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute (location = 0)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Color attribute (location = 1)
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Unbind buffers
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Store window and other resources as needed
    // For simplicity, we'll keep the window active within this function
    // In a more complex setup, consider storing these as member variables
    while (!glfwWindowShouldClose(window)) {
        // Input
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        // Rendering commands here
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Draw our triangle
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Clean up resources
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    // Terminate GLFW
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Renderer::Render()
{
    // In this simple example, rendering is handled within Init()
    // For a more complex application, consider separating initialization and rendering
}

void Renderer::Shutdown()
{
    // Clean up any allocated resources if necessary
    // In this example, cleanup is handled in Init()
}

} // namespace MyProject
