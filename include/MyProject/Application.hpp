#pragma once

namespace MyProject {
class Application
{
public:
    Application() = default;
    ~Application() = default;

    bool Init();
    void Run();
    void Shutdown();

private:
// not sure what to put right now    
};

} // namespace MyProject