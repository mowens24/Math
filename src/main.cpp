#include "../include/MyProject/Application.hpp"
#include <iostream>

int main(int agrgc, char** argv)
{
    MyProject::Application app;
    if(!app.Init()) {
        std::cerr << "Failed to initialize Application.\n";
        return -1;
    }
    app.Run();
    app.Shutdown();
    return 0;
}