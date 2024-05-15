#pragma once

#ifndef _RELEASE_
#    define LOG_SYSTEM_INIT(...) Pale::Core::Log_Manager::Initialize(__VA_ARGS__)

#    define PALE_ENGINE_TRACE(...)                   \
        if (spdlog::get("PALE") != nullptr) {        \
            spdlog::get("PALE")->trace(__VA_ARGS__); \
        }
#    define PALE_ENGINE_DEBUG(...)                   \
        if (spdlog::get("PALE") != nullptr) {        \
            spdlog::get("PALE")->debug(__VA_ARGS__); \
        }
#    define PALE_ENGINE_INFO(...)                   \
        if (spdlog::get("PALE") != nullptr) {       \
            spdlog::get("PALE")->info(__VA_ARGS__); \
        }
#    define PALE_ENGINE_WARNING(...)                \
        if (spdlog::get("PALE") != nullptr) {       \
            spdlog::get("PALE")->warn(__VA_ARGS__); \
        }
#    define PALE_ENGINE_ERROR(...)                   \
        if (spdlog::get("PALE") != nullptr) {        \
            spdlog::get("PALE")->error(__VA_ARGS__); \
        }
#    define PALE_ENGINE_FATAL(...)                      \
        if (spdlog::get("PALE") != nullptr) {           \
            spdlog::get("PALE")->critical(__VA_ARGS__); \
        }

#    define CLIENT_APP_TRACE(...)                   \
        if (spdlog::get("APP") != nullptr) {        \
            spdlog::get("APP")->trace(__VA_ARGS__); \
        }
#    define CLIENT_APP_DEBUG(...)                   \
        if (spdlog::get("APP") != nullptr) {        \
            spdlog::get("APP")->debug(__VA_ARGS__); \
        }
#    define CLIENT_APP_INFO(...)                   \
        if (spdlog::get("APP") != nullptr) {       \
            spdlog::get("APP")->info(__VA_ARGS__); \
        }
#    define CLIENT_APP_WARNING(...)                \
        if (spdlog::get("APP") != nullptr) {       \
            spdlog::get("APP")->warn(__VA_ARGS__); \
        }
#    define CLIENT_APP_ERROR(...)                   \
        if (spdlog::get("APP") != nullptr) {        \
            spdlog::get("APP")->error(__VA_ARGS__); \
        }
#    define CLIENT_APP_FATAL(...)                      \
        if (spdlog::get("APP") != nullptr) {           \
            spdlog::get("APP")->critical(__VA_ARGS__); \
        }
#else
// Disable logs for 'Release' builds
#    define LOG_SYSTEM_INIT(...) (void)0

#    define PALE_ENGINE_TRACE(...) (void)0
#    define PALE_ENGINE_DEBUG(...) (void)0
#    define PALE_ENGINE_INFO(...) (void)0
#    define PALE_ENGINE_WARNING(...) (void)0
#    define PALE_ENGINE_ERROR(...) (void)0
#    define PALE_ENGINE_FATAL(...) (void)0

#    define CLIENT_APP_TRACE(...) (void)0
#    define CLIENT_APP_DEBUG(...) (void)0
#    define CLIENT_APP_INFO(...) (void)0
#    define CLIENT_APP_WARNING(...) (void)0
#    define CLIENT_APP_ERROR(...) (void)0
#    define CLIENT_APP_FATAL(...) (void)0
#endif
