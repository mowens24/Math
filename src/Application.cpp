// Temporary NOTHINNESS

#include "../third_party/glad/include/KHR/khrplatform.h"
#include "../third_party/glad/include/glad/glad.h"
#include "../third_party/glfw/include/GLFW/glfw3.h"
#include "../third_party/glm/glm/glm.hpp"
#include "../third_party/muparser/include/muParser.h"

#include "../include/MyProject/Application.hpp"
#include "../include/MyProject/Renderer.hpp"
#include "../include/MyProject/ImGuiLayer.hpp"
/*
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <muParser.h>
*/
namespace MyProject {


static GLFWwindow* s_Window = nullptr; // example

bool Application::Init()
{
    // Init GLFW
    if(!glfwInit()) {
        return false;
    }

    //Window hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Create window
    s_Window = glfwCreateWindow(1280, 720, "MyProject", nullptr, nullptr);
    if(!s_Window) {
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(s_Window);

    // Init GLAD
    // if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    //     return false;
    // }

    // Init ImGui
    ImGuiLayer::Init(s_Window);

    // Init Renderer
    Renderer::Init();

    return true;
}

void Application::Run()
{
    while(!glfwWindowShouldClose(s_Window))
    {
        // Poll events
        glfwPollEvents();

        // Start ImGui frame
        ImGui::BeginFrame();

        // Debug window
        ImGui::Begin("Demo"); ImGui::End();

        // Render ImGui
        Renderer::Render();

        // End ImGui frame
        ImGui::EndFrame();

        // Swap buffers
        glfwSwapBuffers(s_Window);
    }
}


void Application::Shutdown()
{
    // Cleanup
    Renderer::Shutdown();
    ImGui::Shutdown();

    glfwDestroyWindow(s_Window);
    glfwTerminate();
}

} // namespace MyProject