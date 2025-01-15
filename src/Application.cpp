#include "../include/MyProject/Application.hpp"
#include "../include/MyProject/Renderer.hpp"
#include "../include/MyProject/ImGuiLayer.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <iostream>

namespace MyProject {

Application::Application()
    : m_Window(nullptr)
    , m_ImGuiLayer(new ImGuiLayer())
    , m_Renderer(new Renderer())
{}

Application::~Application()
{
    delete m_ImGuiLayer;
    delete m_Renderer;
}

bool Application::Init()
{
    // 1) Init GLFW
    if (!glfwInit()) {
        return false;
    }

    // 2) Window hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // 3) Create window
    m_Window = glfwCreateWindow(1280, 720, "MyProject", nullptr, nullptr);
    if (!m_Window) {
        std::cerr << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return false;
    }

    // 4) Make context current
    glfwMakeContextCurrent(m_Window);

    // 5) Load GL with GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD." << std::endl;
        return false;
    }
    // For testing, set a clear color so we don't see just black
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    
    // 6) Setup ImGui
    m_ImGuiLayer->Init(m_Window);

    // 7) Init our Renderer (now that we have a valid context)
    m_Renderer->Init();

    return true;
}

void Application::Run()
{
    // Main loop
    while (!glfwWindowShouldClose(m_Window)) {
        // Poll events
        glfwPollEvents();

        // Start ImGui frame
        m_ImGuiLayer->Begin();
        {
            // (Debug UI example)
            ImGui::Begin("Demo");
            ImGui::Text("Hello from ImGui!");
            ImGui::End();
        }

        // Render ImGui
        ImGui::Render();

        // End ImGui
        m_ImGuiLayer->End();

        // Clear screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render with our renderer
        m_Renderer->Render();

        // Swap buffers
        glfwSwapBuffers(m_Window);
    }
}

void Application::Shutdown()
{
    // Cleanup
    m_Renderer->Shutdown();
    delete m_Renderer;
    m_Renderer = nullptr;

    m_ImGuiLayer->Shutdown();
    delete m_ImGuiLayer;
    m_ImGuiLayer = nullptr;
    
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

} // namespace MyProject
