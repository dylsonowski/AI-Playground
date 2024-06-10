#include "palepch.hpp"
#include "Application.hpp"

namespace Pale {
void Application::Run() {
#ifndef _RELEASE_
	if (LOG_SYSTEM_INIT(Core::LOGGING_METHOD::FILE_AND_TERMINAL) == false) {
		return;
	}
#endif
	std::cout << std::chrono::system_clock::now() << std::endl;
	while (true) {
		if (std::cin.get()) break;
	}
}
}  // namespace Pale