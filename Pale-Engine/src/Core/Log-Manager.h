// https://github.com/gabime/spdlog/wiki
#pragma once
#include <spdlog.h>

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
  bool AddSink(std::string sinkName, spdlog::sink_ptr sink, spdlog::level::level_enum level, std::string format);
  bool RemoveSink(std::string sinkName);

  bool AddLogger();
  bool RemoveLogger(std::string loggerName);
  

  // Attributes
  static std::map<std::string, spdlog::sink_ptr> s_sinks;
  static std::map<std::string, std::shared_ptr<spdlog::logger>> s_loggers;
};
} // namespace Pale::Core