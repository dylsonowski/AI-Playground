// https://spdlog.docsforge.com/
#pragma once
#include "config/log-manager.config.h"

namespace Pale::Core {
class Log_Manager {
public:
  Log_Manager() = default;
  ~Log_Manager() = default;

  void Initialize();
  void Shutdown() { spdlog::shutdown(); }

private:
  void ValidateConfig(LogManagerConfig config);
};
} // namespace Pale::Core