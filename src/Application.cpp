#include "../include/MyProject/Application.hpp"
#include "../include/MyProject/Renderer.hpp"
#include "../include/MyProject/ImGuiLayer.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>
#include <imgui.h>
#include <iostream>
#include "../third_party/exprtk/exprtk.hpp"

/* Forward declaration of EvaluateExpressionStub
double EvaluateExpressionStub(const char* expression, float x);
void PlotEquationStub(const char* expression);
*/
namespace MyProject {

char eqBuffer[256] = "";
float xVal = 0.0f;
float lastResult = 0.0f;

double EvaluateEquationExprTk(const char* expression, double x)
{
    exprtk::symbol_table<double> symbol_table;
    symbol_table.add_variable("x", x);
    symbol_table.add_constants();

    exprtk::expression<double> expr;
    expr.register_symbol_table(symbol_table);

    exprtk::parser<double> parser;
    if (!parser.compile(expression, expr))
    {
        std::cerr << "Error: " << parser.error() << std::endl;
        return 0.0;
    }

    return expr.value();
}

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
    
        // 1) Start ImGui frame
        m_ImGuiLayer->Begin();
    
        // 2) Build ImGui windows

        // Equation Window
        ImGui::Begin("Equation Window");
        ImGui::InputText("Equation", eqBuffer, IM_ARRAYSIZE(eqBuffer));
        ImGui::SliderFloat("x", &xVal, -10.f, 10.f);

        if (ImGui::Button("Compute"))
        {
            // Use ExprTk to evaluate eqBuffer at xVal
            double result = EvaluateEquationExprTk(eqBuffer, static_cast<double>(xVal));
            lastResult = static_cast<float>(result); // store for display

            // Also log it
            std::cout << "[Compute] eq='" << eqBuffer
                      << "', x=" << xVal
                      << " => result=" << result << std::endl;
        }

        ImGui::SameLine();
        ImGui::Text("Result: %.3f", lastResult);
        ImGui::End(); // End Equation Window

        // Graph Settings Panel
        ImGui::Begin("Graph Settings");
        static float xMin = -10.0f, xMax = 10.0f;
        static int steps = 100;
        ImGui::SliderFloat("X Min", &xMin, -100.0f, 0.0f);
        ImGui::SliderFloat("X Max", &xMax, 0.0f, 100.0f);
        ImGui::SliderInt("Steps", &steps, 1, 1000);
        ImGui::End(); // End Graph Settings

        // 3) Render and End frame
        m_ImGuiLayer->End();
    
        // 4) Swap buffers
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
