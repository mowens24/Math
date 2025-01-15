#pragma once
#include "Renderer.hpp"
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
    void RenderImGuiUI();
private:
    GLFWwindow* m_Window;      
    ImGuiLayer* m_ImGuiLayer;
    Renderer* m_Renderer; 
};

} // namespace MyProject