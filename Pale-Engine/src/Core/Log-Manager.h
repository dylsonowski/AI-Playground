// https://spdlog.docsforge.com/
#pragma once
#include "spdlog/spdlog.h"

namespace Pale::Core {
class Log_Manager {
public:
  Log_Manager() = default;
  ~Log_Manager() = default;

  void Initialize();
  void Shutdown() { spdlog::shutdown(); }
};
} // namespace Pale::Core