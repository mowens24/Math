#pragma once

// Forward declare GLFWwindow
struct GLFWwindow;

namespace MyProject {

// Forward declare ImGuiLayer
class ImGuiLayer;

class Application {
public:
    Application();
    ~Application();
    
    bool Init();
    void Run();
    void Shutdown();

private:
    GLFWwindow* m_Window;      // Pointer is okay with forward declaration
    ImGuiLayer* m_ImGuiLayer;  // Changed to pointer since we only have forward declaration
};

} // namespace MyProject