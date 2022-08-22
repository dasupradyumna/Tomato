#ifndef TOMATO_INCLUDE_TOMATO_LOGGER_HPP_1646142163
#define TOMATO_INCLUDE_TOMATO_LOGGER_HPP_1646142163

#include <../src/Core.hpp>

// pch spdlog/spdlog.h
// pch spdlog/fmt/ostr.h

// pch memory

namespace tmt
{
  class API logger {
  public:
    static void init();

    static std::shared_ptr<spdlog::logger> &core_logger() { return __core_logger; }

    static std::shared_ptr<spdlog::logger> &client_logger() { return __client_logger; }

  private:
    static std::shared_ptr<spdlog::logger> __core_logger;
    static std::shared_ptr<spdlog::logger> __client_logger;
  };
}

#define TMT_CORE_TRACE(...)    ::tmt::logger::core_logger()->trace(__VA_ARGS__)
#define TMT_CORE_DEBUG(...)    ::tmt::logger::core_logger()->debug(__VA_ARGS__)
#define TMT_CORE_INFO(...)     ::tmt::logger::core_logger()->info(__VA_ARGS__)
#define TMT_CORE_WARN(...)     ::tmt::logger::core_logger()->warn(__VA_ARGS__)
#define TMT_CORE_ERROR(...)    ::tmt::logger::core_logger()->error(__VA_ARGS__)
#define TMT_CORE_CRITICAL(...) ::tmt::logger::core_logger()->critical(__VA_ARGS__)

#define TMT_CLIENT_TRACE(...)    ::tmt::logger::client_logger()->trace(__VA_ARGS__)
#define TMT_CLIENT_DEBUG(...)    ::tmt::logger::client_logger()->debug(__VA_ARGS__)
#define TMT_CLIENT_INFO(...)     ::tmt::logger::client_logger()->info(__VA_ARGS__)
#define TMT_CLIENT_WARN(...)     ::tmt::logger::client_logger()->warn(__VA_ARGS__)
#define TMT_CLIENT_ERROR(...)    ::tmt::logger::client_logger()->error(__VA_ARGS__)
#define TMT_CLIENT_CRITICAL(...) ::tmt::logger::client_logger()->critical(__VA_ARGS__)

#endif
