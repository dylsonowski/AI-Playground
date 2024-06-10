#include "palepch.hpp"
#include "Log-Manager.hpp"

namespace Pale::Core {
//* [<COLOR_START><LEVEL><COLOR_END>] [<HH:MM:SS>.<MILLISECOND>] <LOGGER_NAME>: <MESSAGE>
//* Example: [ERROR] [15:36:24.678] PALE: Error message
const std::string logMessagePatternV1 = "[%^%l%$] [%T.%e] %n: %v";
//* <COLOR_START>[<HH:MM:SS>.<MILLISECOND>] [Assertion failed!]: <MESSAGE> at <FILE_PATH_LINE> -> <FUNCTION_NAME>()<COLOR_END>
//* Example: [15:36:24.678] [Assertion failed!]: Failed assertion message at C:/location/file.cpp -> myFunction()
// IMPORTANT: use SPDLOG_TRACE(..), SPDLOG_INFO(...) etc. instead of spdlog::trace(...) in 'Log-Macros.h'
const std::string logMessagePatternAssertion = "%^[%T.%e] [Assertion failed!]: %v at %@ -> %!()%$";

std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> Log_Manager::s_terminalSink;
std::shared_ptr<spdlog::sinks::basic_file_sink_mt> Log_Manager::s_fileSink;

std::shared_ptr<spdlog::logger> Log_Manager::s_engineLogger;
std::shared_ptr<spdlog::logger> Log_Manager::s_clientLogger;
std::shared_ptr<spdlog::logger> Log_Manager::s_assertionLogger;

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

			// Assertion logger configuration
			s_assertionLogger = std::make_shared<spdlog::logger>("ASSERT", s_terminalSink);
			s_assertionLogger->set_level(spdlog::level::critical);
			s_assertionLogger->flush_on(spdlog::level::critical);
			s_assertionLogger->set_pattern(logMessagePatternAssertion);
			spdlog::register_logger(s_assertionLogger);
			break;
		}
		case LOGGING_METHOD::FILE_ONLY: {
			// File sink configuration
			std::string logFileName = "logs/AppRuntime(1).log";
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
			std::string logFileName = "logs/runtime/AppRuntime(1).log";
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
		}
	}

	return true;
}
}  // namespace Pale::Core
