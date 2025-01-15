#include "../include/MyProject/Renderer.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

namespace MyProject {

// Utility to load file into a string
static std::string LoadShaderFile(const std::string& path)
{
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Could not open shader file: " << path << std::endl;
        return "";
    }
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}
// Utility to compile a single shader
static GLuint CompileShader(GLenum type, const std::string& source)
{
    GLuint shader = glCreateShader(type);
    const char* srcPtr = source.c_str();
    glShaderSource(shader, 1, &srcPtr, nullptr);
    glCompileShader(shader);

    // Check for compilation errors
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLint logSize;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logSize);
        std::string infoLog(logSize, ' ');
        glGetShaderInfoLog(shader, logSize, &logSize, &infoLog[0]);
        std::cerr << "Shader compilation error:\n" << infoLog << std::endl;
        glDeleteShader(shader);
        return 0;
    }
    return shader;
}

Renderer::Renderer()
    : m_ShaderProgram(0), m_VAO(0), m_VBO(0), m_EBO(0)
{
    // Constructor is empty or just logs something.
    // No OpenGL calls here!
}

Renderer::~Renderer()
{
    Shutdown();
}

void Renderer::Init()
{
    // 1) Create/compile/link a shader program
    m_ShaderProgram = CreateShaderProgram("../shaders/vertex_shader.glsl",
                                          "../shaders/fragment_shader.glsl");
    if (!m_ShaderProgram) {
        std::cerr << "Renderer::Init() - Failed to create shader program!\n";
        return;
    }

    // 2) Generate VAO, VBO, EBO
    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);

    // 3) Generate buffers
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);
    
    // 4) Simple triangle data
    float vertices[] = {
         0.0f,  0.5f, 0.0f, // top
         0.5f, -0.5f, 0.0f, // bottom-right
        -0.5f, -0.5f, 0.0f  // bottom-left
    };
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int indices[] = { 0, 1, 2 };
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // 4) Vertex attribute pointer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
                          3 * sizeof(float),
                          (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0); // unbind
}

void Renderer::Render()
{
    // Use our shader
    glUseProgram(m_ShaderProgram);

    // Bind the VAO
    glBindVertexArray(m_VAO);

    // Draw
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
    
    // Unbind
    glBindVertexArray(0);
}

void Renderer::Shutdown()
{
    if (m_ShaderProgram) {
        glDeleteProgram(m_ShaderProgram);
        m_ShaderProgram = 0;
    }
    if (m_VBO) {
        glDeleteBuffers(1, &m_VBO);
        m_VBO = 0;
    }
    if (m_EBO) {
        glDeleteBuffers(1, &m_EBO);
        m_EBO = 0;
    }
    if (m_VAO) {
        glDeleteVertexArrays(1, &m_VAO);
        m_VAO = 0;
    }
}

GLuint Renderer::CreateShaderProgram(const std::string& vertPath,
                                     const std::string& fragPath)
{
    std::string vertSource = LoadShaderFile(vertPath);
    std::string fragSource = LoadShaderFile(fragPath);
    if (vertSource.empty() || fragSource.empty())
        return 0;

    // Compile shaders
    GLuint vert = CompileShader(GL_VERTEX_SHADER,   vertSource);
    if (!vert) return 0;

    GLuint frag = CompileShader(GL_FRAGMENT_SHADER, fragSource);
    if (!frag) {
        glDeleteShader(vert);
        return 0;
    }

    GLuint program = glCreateProgram();
    glAttachShader(program, vert);
    glAttachShader(program, frag);
    glLinkProgram(program);

    // Check link errors
    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        GLint logSize;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logSize);
        std::string infoLog(logSize, ' ');
        glGetProgramInfoLog(program, logSize, &logSize, &infoLog[0]);
        std::cerr << "Shader link error:\n" << infoLog << std::endl;
        glDeleteProgram(program);
        program = 0;
    }

    // cleanup
    glDeleteShader(vert);
    glDeleteShader(frag);

    return program;
}

} // namespace MyProject
