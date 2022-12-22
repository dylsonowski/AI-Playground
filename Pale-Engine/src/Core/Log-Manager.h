// https://spdlog.docsforge.com/
#pragma once
#include "config/log-manager.config.h"

namespace Pale::Core {
class Log_Manager {
public:
	Log_Manager() = default;
	~Log_Manager() = default;

	void Initialize(LOGGING_METHOD loggingMethod, const char* logFormat = "%^[%l] [%T] %n: %v%$");
	void Shutdown() { spdlog::shutdown(); }
};
} // namespace Pale::Core