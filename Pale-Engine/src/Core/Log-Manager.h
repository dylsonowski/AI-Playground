#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

namespace Pale::Core {
class Log_Manager {
public:
	Log_Manager() = default;
	~Log_Manager() = default;

	void Initialize(LOGGING_METHOD loggingMethod, const char* logFormat = "%^[%l] [%T] %n: %v%$");
	void Shutdown() { spdlog::shutdown(); }
};
} // namespace Pale::Core