#include "../include/MyProject/ImGuiLayer.hpp"

//Dear ImGui headers
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace MyProject {

void ImGuiLayer::Init(GLFWwindow* window)
{
    IMGUI_CHECKVERSION();
    ImGUI::CreateContext();
    ImGUI::StyleColorsDark();

    // Platform renderer backends
    // GLFW + OpenGL3
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330 core"
)

void ImGuiLayer::BeginFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}
void ImGuiLayer::EndFrame()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

}
void ImGuiLayer::Shutdown()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

} // namespace MyProject   