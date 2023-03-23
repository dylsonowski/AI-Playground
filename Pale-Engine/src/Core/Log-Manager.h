// https://github.com/gabime/spdlog/wiki
#pragma once
#include <spdlog/spdlog.h>

namespace Pale::Core {
class Log_Manager {
public:
  Log_Manager() = default;
  ~Log_Manager() = default;

  void Initialize();
  void Shutdown() { spdlog::shutdown(); }

private:
  // Methods
  // Use ONLY in 'Initialize()' method!
  bool AddSink(const char* sinkName, spdlog::sink_ptr sink, spdlog::level::level_enum level, const char* format);
  bool RemoveSink(const char* sinkName);

  bool AddLogger();
  bool RemoveLogger(const char* loggerName);
  

  // Attributes
  static std::map<const char*, spdlog::sink_ptr> s_sinks;
  static std::map<const char*, std::shared_ptr<spdlog::logger>> s_loggers;
};
} // namespace Pale::Core