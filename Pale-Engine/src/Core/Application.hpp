#pragma once
namespace Pale {
class Application {
public:
    Application() = default;
    virtual ~Application() = default;

    void Run();

private:
    std::vector<int> dwd;
};

// To be defined by client
Application* CreateApplication();
}  // namespace Pale
