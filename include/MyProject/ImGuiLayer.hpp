// include/MyProject/ImGuiLayer.hpp

#ifndef MYPROJECT_IMGUI_LAYER_HPP
#define MYPROJECT_IMGUI_LAYER_HPP

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h> // Required for GLFWwindow

class ImGuiLayer {
public:
    void Init(GLFWwindow* window);
    void Shutdown();
    void Begin();
    void End();
};

#endif // MYPROJECT_IMGUI_LAYER_HPP
