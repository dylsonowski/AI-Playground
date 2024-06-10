// https://github.com/gabime/spdlog/wiki
#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

namespace Pale::Core {
enum class LOGGING_METHOD { FILE_AND_TERMINAL = 0, FILE_ONLY, TERMINAL_ONLY };

class Log_Manager {
public:
	Log_Manager(Log_Manager& other) = delete;
	~Log_Manager() = default;

	void operator=(Log_Manager& other) = delete;

	static bool Initialize(LOGGING_METHOD loggingMethod);

	void Shutdown() { spdlog::shutdown(); }

private:
	Log_Manager() = default;

	// Sinks
	static std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> s_terminalSink;
	static std::shared_ptr<spdlog::sinks::basic_file_sink_mt> s_fileSink;

	// Loggers
	static std::shared_ptr<spdlog::logger> s_engineLogger;
	static std::shared_ptr<spdlog::logger> s_clientLogger;
	static std::shared_ptr<spdlog::logger> s_assertionLogger;
};
}  // namespace Pale::Core
