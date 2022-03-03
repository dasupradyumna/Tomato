#ifndef TOMATO_INCLUDE_TOMATO_LOGGER_H_1646142163
#define TOMATO_INCLUDE_TOMATO_LOGGER_H_1646142163

#include "../src/Core.h"

// pch include spdlog/spdlog.h
// pch include spdlog/fmt/ostr.h

// pch include memory

namespace tmt
{
  class API logger
  {
  public:
    static void init();

    inline static std::shared_ptr<spdlog::logger>& get_core_logger() { return __core_logger; }

    inline static std::shared_ptr<spdlog::logger>& get_client_logger() { return __client_logger; }

  private:
    static std::shared_ptr<spdlog::logger> __core_logger;
    static std::shared_ptr<spdlog::logger> __client_logger;
  };
}

#define TMT_CORE_TRACE(...)    ::tmt::logger::get_core_logger()->trace(__VA_ARGS__)
#define TMT_CORE_DEBUG(...)    ::tmt::logger::get_core_logger()->debug(__VA_ARGS__)
#define TMT_CORE_INFO(...)     ::tmt::logger::get_core_logger()->info(__VA_ARGS__)
#define TMT_CORE_WARN(...)     ::tmt::logger::get_core_logger()->warn(__VA_ARGS__)
#define TMT_CORE_ERROR(...)    ::tmt::logger::get_core_logger()->error(__VA_ARGS__)
#define TMT_CORE_CRITICAL(...) ::tmt::logger::get_core_logger()->critical(__VA_ARGS__)

#define TMT_CLIENT_TRACE(...)    ::tmt::logger::get_client_logger()->trace(__VA_ARGS__)
#define TMT_CLIENT_DEBUG(...)    ::tmt::logger::get_client_logger()->debug(__VA_ARGS__)
#define TMT_CLIENT_INFO(...)     ::tmt::logger::get_client_logger()->info(__VA_ARGS__)
#define TMT_CLIENT_WARN(...)     ::tmt::logger::get_client_logger()->warn(__VA_ARGS__)
#define TMT_CLIENT_ERROR(...)    ::tmt::logger::get_client_logger()->error(__VA_ARGS__)
#define TMT_CLIENT_CRITICAL(...) ::tmt::logger::get_client_logger()->critical(__VA_ARGS__)

#endif
