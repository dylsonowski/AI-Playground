#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

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
		: _loggerName(loggerName),
		  _logFormat(logFormat),
		  _logLevel(logLevel) {}
};

struct LogManagerConfig {
	LogManagerConfig() {
		// Logging method config
		_loggingMethod = LOGGING_METHOD::BASIC;

		// Loggers list config
		_loggers.emplace_back(LoggerConfig("PALE", "%^[%c][%n][%l] %v%$: %@ -> %!", spdlog::level::trace));
		_loggers.emplace_back(LoggerConfig("APP", "%^[%c][%n][%l] %v%$: %@ -> %!", spdlog::level::warn));

		// Logger sinks config
		std::string logFileName = "logs/AppRuntime(" + std::format("{:%d-%m-%Y %H:%M:%OS}", std::chrono::system_clock::now()) + ").log";
		_sinks.emplace_back(std::make_pair(std::make_shared<spdlog::sinks::basic_file_sink_mt>(logFileName, true), spdlog::level::trace));

		_sinks.emplace_back(std::make_pair(std::make_shared<spdlog::sinks::stdout_color_sink_mt>(), spdlog::level::warn));
	}

	~LogManagerConfig() = default;

	// Attributes
	LOGGING_METHOD _loggingMethod;
	std::vector<LoggerConfig> _loggers;
	std::vector<std::pair<spdlog::sink_ptr, spdlog::level::level_enum>> _sinks;
} c_logManagerConfig;
