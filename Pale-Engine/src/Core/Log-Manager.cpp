#include "palepch.h"
#include "Log-Manager.h"

namespace Pale::Core {
    void Log_Manager::Initialize(LOGGING_METHOD loggingMethod, const char* logFormat) {
        static std::vector<spdlog::sink_ptr> s_sinks; // List of all available output handlers
        spdlog::set_pattern(logFormat); // Setting pattern of the log messages ()

        switch(loggingMethod) {
            case LOGGING_METHOD::FILE_ONLY: {
                
            }
        }
    }
}