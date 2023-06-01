#include "palepch.h"
#include "Application.h"

namespace Pale {
	void Application::Run() {
		if (LOG_SYSTEM_INIT(Core::LOGGING_METHOD::FILE_AND_TERMINAL) == true) {
			while (true) {}
		}
	}
} // namespace Pale