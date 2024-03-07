#include "palepch.h"
#include "Log-Manager.hpp"

namespace Pale::Core {
	const std::string logMessagePatternV1 = "%^[%l] [%T.%e] %n: %v%$";
	const std::string logMessagePatternV2 = "%^[%c][%n][%l] %v%$: %@ -> %!"; // IMPORTANT: use SPDLOG_TRACE(..), SPDLOG_INFO(...) etc. instead of spdlog::trace(...) in 'Log-Macros.h'

	std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> Log_Manager::s_terminalSink;
	std::shared_ptr<spdlog::sinks::basic_file_sink_mt> Log_Manager::s_fileSink;

	std::shared_ptr<spdlog::logger> Log_Manager::s_engineLogger;
	std::shared_ptr<spdlog::logger> Log_Manager::s_clientLogger;

	bool Log_Manager::Initialize(LOGGING_METHOD loggingMethod) {
		switch (loggingMethod) {
		case LOGGING_METHOD::TERMINAL_ONLY: {
			// Terminal sink configuration
			s_terminalSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
			s_terminalSink->set_pattern(logMessagePatternV1);
			s_terminalSink->set_level(spdlog::level::trace);

			// Pale engine logger configuration
			s_engineLogger = std::make_shared<spdlog::logger>("PALE", s_terminalSink);
			s_engineLogger->set_level(spdlog::level::trace);
			s_engineLogger->flush_on(spdlog::level::trace);
			spdlog::register_logger(s_engineLogger);

			// Client application logger configuration
			s_clientLogger = std::make_shared<spdlog::logger>("APP", s_terminalSink);
			s_clientLogger->set_level(spdlog::level::trace);
			s_clientLogger->flush_on(spdlog::level::trace);
			spdlog::register_logger(s_clientLogger);
			break;
		}
		case LOGGING_METHOD::FILE_ONLY: {
			// File sink configuration
			std::string logFileName = "logs/AppRuntime(" + std::format("{:%d-%m-%Y %H:%M:%OS}", std::chrono::system_clock::now()) + ").log";
			s_fileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(logFileName, true);
			s_fileSink->set_pattern(logMessagePatternV1);
			s_fileSink->set_level(spdlog::level::trace);

			// Pale engine logger configuration
			s_engineLogger = std::make_shared<spdlog::logger>("PALE", s_fileSink);
			s_engineLogger->set_level(spdlog::level::trace);
			s_engineLogger->flush_on(spdlog::level::trace);
			spdlog::register_logger(s_engineLogger);

			// Client application logger configuration
			s_clientLogger = std::make_shared<spdlog::logger>("APP", s_fileSink);
			s_clientLogger->set_level(spdlog::level::trace);
			s_clientLogger->flush_on(spdlog::level::trace);
			spdlog::register_logger(s_clientLogger);
			break;
		}
		case LOGGING_METHOD::FILE_AND_TERMINAL: {
			static std::vector<spdlog::sink_ptr> s_sinksList;

			// Terminal sink configuration
			s_terminalSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
			s_terminalSink->set_pattern(logMessagePatternV1);
			s_terminalSink->set_level(spdlog::level::warn);
			s_sinksList.push_back(s_terminalSink);

			// File sink configuration
			std::string logFileName = "logs/runtime/AppRuntime(" + std::format("{:%d-%m-%Y %Hh_%Mm_%OSs}", std::chrono::system_clock::now()) + ").log";
			s_fileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(logFileName, true);
			s_fileSink->set_pattern(logMessagePatternV1);
			s_fileSink->set_level(spdlog::level::trace);
			s_sinksList.push_back(s_fileSink);

			// Pale engine logger configuration
			s_engineLogger = std::make_shared<spdlog::logger>("PALE", s_sinksList.begin(), s_sinksList.end());
			s_engineLogger->set_level(spdlog::level::trace);
			s_engineLogger->flush_on(spdlog::level::trace);
			spdlog::register_logger(s_engineLogger);

			// Client application logger configuration
			s_clientLogger = std::make_shared<spdlog::logger>("APP", s_sinksList.begin(), s_sinksList.end());
			s_clientLogger->set_level(spdlog::level::trace);
			s_clientLogger->flush_on(spdlog::level::trace);
			spdlog::register_logger(s_clientLogger);
			break;
		}
		default: {
			return false;
			break;
		}
		}

		return true;
	}
} // namespace Pale::Core