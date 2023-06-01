#pragma once

namespace Pale {
class Application {
public:
	Application() = default;
	virtual ~Application() = default;

	void Run();

private:
};

// To be defined by client
Application *CreateApplication();
} // namespace Pale