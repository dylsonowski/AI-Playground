#include "Log-Manager.h"

#include "palepch.h"


namespace Pale::Core {
	void Log_Manager::Initialize() {
		// static std::vector<spdlog::sink_ptr> s_sinks; // List of all available output handlers
		// spdlog::set_pattern(logFormat); // Setting pattern of the log messages ()

		// switch(loggingMethod) {
		//     case LOGGING_METHOD::FILE_ONLY: {

		//     }
		// }
	}

	bool Log_Manager::AddSink(const char *sinkName, spdlog::sink_ptr sink, spdlog::level::level_enum level, const char *format) {
		auto newSink = sink;
		newSink->set_level(level);
		newSink->set_pattern(format);

		int previousSinkCount = s_sinks.size();
		s_sinks.insert({sinkName, newSink});

		return s_sinks.size() > previousSinkCount;
	}

	bool Log_Manager::RemoveSink(const char *sinkName) {
		int previousSinkCount = s_sinks.size();
		s_sinks.erase(sinkName);

		return s_sinks.size() < previousSinkCount;
	}

	bool Log_Manager::RemoveLogger(const char* loggerName) {	  
        int previousLoggersCount = s_loggers.size();
		s_loggers.erase(loggerName);
		spdlog::register_logger

		return s_loggers.size() < previousLoggersCount;
	}

} // namespace Pale::Core