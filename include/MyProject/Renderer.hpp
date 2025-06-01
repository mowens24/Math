#pragma once

#include <string>
// You can include <glad/glad.h> here if you like
#include <glad/glad.h>

namespace MyProject {

class Renderer
{
public:
    Renderer();
    ~Renderer();

    // Called once after an OpenGL context is already created in Application
    void Init();

    // Called every frame to draw
    void Render();

    // Cleanup GL objects
    void Shutdown();

private:
    // A helper to create/compile/link a shader program
    GLuint CreateShaderProgram(const std::string& vertexPath,
                               const std::string& fragmentPath);

private:
    GLuint m_ShaderProgram;
    GLuint m_VAO;
    GLuint m_VBO;
    GLuint m_EBO;
};

} // namespace MyProject
