#pragma once
    
//

struct GLFWwindow;

namespace MyProject {


class ImGuiLayer 
{
public:
    // Init ImGui (create context, set style, init backends)
    static void Init(GLFWwindow* window);

    // Start a new ImGui frame
    static void BeginFrame();

    // Render frame
    static void EndFrame();

    // Shutdown ImGui (destroy context, shutdown backends)
    static void Shutdown();
};

} // namespace MyProject