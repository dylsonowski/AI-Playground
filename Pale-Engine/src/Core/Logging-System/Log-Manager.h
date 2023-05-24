// https://github.com/gabime/spdlog/wiki
#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

namespace Pale::Core {
	enum class LOGGING_METHOD {
		FILE_AND_TERMINAL = 0,
		FILE_ONLY,
		TERMINAL_ONLY
	};

	class Log_Manager {
	public:
		Log_Manager() = default;
		~Log_Manager() = default;

		static bool Initialize(LOGGING_METHOD loggingMethod);
		void Shutdown() {spdlog::shutdown();}

	private:
		// Sinks
		static std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> s_terminalSink;
		static std::shared_ptr<spdlog::sinks::basic_file_sink_mt> s_fileSink;

		// Loggers
		static std::shared_ptr<spdlog::logger> s_engineLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	};
} // namespace Pale::Core