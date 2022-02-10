#pragma once

#include "../src/Core.h"

#include <memory>
#include <spdlog/spdlog.h>

namespace TM
{
  class ENG_API Logger
  {
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;

  public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

    inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
  };
}

#define CORE_TRACE(...)    ::TM::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define CORE_DEBUG(...)    ::TM::Logger::GetCoreLogger()->debug(__VA_ARGS__)
#define CORE_INFO(...)     ::TM::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_WARN(...)     ::TM::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...)    ::TM::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_CRITICAL(...) ::TM::Logger::GetCoreLogger()->critical(__VA_ARGS__)

#define CLIENT_TRACE(...)    ::TM::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define CLIENT_DEBUG(...)    ::TM::Logger::GetClientLogger()->debug(__VA_ARGS__)
#define CLIENT_INFO(...)     ::TM::Logger::GetClientLogger()->info(__VA_ARGS__)
#define CLIENT_WARN(...)     ::TM::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define CLIENT_ERROR(...)    ::TM::Logger::GetClientLogger()->error(__VA_ARGS__)
#define CLIENT_CRITICAL(...) ::TM::Logger::GetClientLogger()->critical(__VA_ARGS__)
