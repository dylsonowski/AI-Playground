#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

enum class LOGGING_METHOD {
	BASIC = 0,
	FILE_AND_TERMINAL,
	FILE_ONLY,
	TERMINAL_ONLY
};

struct LoggerConfig {
	const char *_loggerName;
	const char *_logFormat;
	spdlog::level::level_enum _logLevel;

	LoggerConfig(const char *loggerName, const char *logFormat, spdlog::level::level_enum logLevel)
		: _loggerName(loggerName), _logFormat(logFormat), _logLevel(logLevel) {}
};

struct LogManagerConfig {
	LOGGING_METHOD _loggingMethod = LOGGING_METHOD::BASIC;
	std::vector<LoggerConfig> _loggers = { LoggerConfig("PALE", "%^[%c][%n][%l] %v%$: %@ -> %!", spdlog::level::trace),
										   LoggerConfig("APP", "%^[%c][%n][%l] %v%$: %@ -> %!", spdlog::level::warn) };
	std::vector<std::pair<spdlog::sink_ptr, spdlog::level::level_enum>> sinks = {
		{ std::make_shared<spdlog::sinks::basic_file_sink_mt>(
			  "logs/AppRuntime(" + std::format("{:%d-%m-%Y %H:%M:%OS}", std::chrono::system_clock::now()) + ").log",
		  true
		  ), spdlog::level::warn },
		{ std::make_shared<spdlog::sinks::stdout_color_sink_mt>(), spdlog::level::trace }
	};
};
