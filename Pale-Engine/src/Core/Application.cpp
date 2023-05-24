#include "palepch.h"
#include "Application.h"

namespace Pale {
void Application::Run() {
	if(LOG_SYSTEM_INIT(Core::LOGGING_METHOD::FILE_AND_TERMINAL) == true) {
		PALE_ENGINE_INFO("Pale application run successfully!");
		PALE_ENGINE_DEBUG("Pale application run successfully!");
		PALE_ENGINE_TRACE("Pale application run successfully!");
		PALE_ENGINE_WARNING("Pale application run successfully!");
		PALE_ENGINE_ERROR("Pale application run successfully!");
		PALE_ENGINE_FATAL("Pale application run successfully!");
		while (true) {}
	}
}
} // namespace Pale