#include "Tomato/Logger.hpp"

// pch include spdlog/sinks/stdout_color_sinks.h

namespace tmt
{
  std::shared_ptr<spdlog::logger> logger::__core_logger {};
  std::shared_ptr<spdlog::logger> logger::__client_logger {};

  void logger::init() {
    spdlog::set_pattern("%^[%T] %n: %v%$");

    __core_logger = spdlog::stdout_color_mt("ENGINE");
    __core_logger->set_level(spdlog::level::trace);

    __client_logger = spdlog::stdout_color_mt("SANDBOX");
    __client_logger->set_level(spdlog::level::trace);
  }
}
