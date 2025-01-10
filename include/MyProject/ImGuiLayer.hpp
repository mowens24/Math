#ifndef MYPROJECT_IMGUI_LAYER_HPP
#define MYPROJECT_IMGUI_LAYER_HPP

// Forward declare GLFWwindow to avoid header inclusion here
struct GLFWwindow;

namespace MyProject {

class ImGuiLayer {
public:
    static void Init(GLFWwindow* window);
    static void Shutdown();
    static void Begin();
    static void End();
};

} // namespace MyProject

#endif // MYPROJECT_IMGUI_LAYER_HPP