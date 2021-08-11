#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Lava
{
    class Logger
    {
    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger> &GetLogger() { return s_Logger; }

    private:
        static std::shared_ptr<spdlog::logger> s_Logger;
    };
}

#define LAVA_TRACE(...) ::Lava::Logger::GetLogger()->trace(__VA_ARGS__)
#define LAVA_INFO(...) ::Lava::Logger::GetLogger()->info(__VA_ARGS__)
#define LAVA_WARN(...) ::Lava::Logger::GetLogger()->warn(__VA_ARGS__)
#define LAVA_ERROR(...) ::Lava::Logger::GetLogger()->error(__VA_ARGS__)
#define LAVA_CRITICAL(...) ::Lava::Logger::GetLogger()->critical(__VA_ARGS__)

#define LAVA_ASSERT(condition, ...)  \
    {                                \
        if (!(condition))            \
            LAVA_ERROR(__VA_ARGS__); \
    }