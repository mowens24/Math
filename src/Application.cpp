#include <glad/glad.h>  // GLAD must be first
#include "../include/MyProject/Application.hpp"
#include "../include/MyProject/Renderer.hpp"
#include "../include/MyProject/ImGuiLayer.hpp"
#include <GLFW/glfw3.h>
#include <imgui.h>

namespace MyProject {

Application::Application() 
    : m_Window(nullptr)
    , m_ImGuiLayer(new ImGuiLayer()) {}

Application::~Application() {
    delete m_ImGuiLayer;
}

bool Application::Init() {
    // Init GLFW
    if(!glfwInit()) {
        return false;
    }
    
    // Window hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    
    // Create window
    m_Window = glfwCreateWindow(1280, 720, "MyProject", nullptr, nullptr);
    if(!m_Window) {
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(m_Window);
    
    // Init GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        return false;
    }
    
    // Init ImGui
    m_ImGuiLayer->Init(m_Window);
    
    // Init Renderer
    Renderer::Init();
    
    return true;
}

void Application::Run() {
    while(!glfwWindowShouldClose(m_Window)) {
        // Poll events
        glfwPollEvents();
        
        // Start ImGui frame
        m_ImGuiLayer->Begin();
        
        // Debug window
        ImGui::Begin("Demo");
        ImGui::End();
        
        // Render
        Renderer::Render();
        
        // End ImGui frame
        m_ImGuiLayer->End();
        
        // Swap buffers
        glfwSwapBuffers(m_Window);
    }
}

void Application::Shutdown() {
    // Cleanup
    Renderer::Shutdown();
    m_ImGuiLayer->Shutdown();
    
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

} // namespace MyProject