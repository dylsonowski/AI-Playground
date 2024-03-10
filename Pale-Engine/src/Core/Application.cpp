#include "palepch.hpp"
#include "Application.hpp"

namespace Pale {
void Application::Run() {
#ifndef _RELEASE_
    if (LOG_SYSTEM_INIT(Core::LOGGING_METHOD::FILE_AND_TERMINAL) != true) {
        return;
    }
#endif
    while (true) {
    }
}
}  // namespace Pale