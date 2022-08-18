#ifndef TOMATO_INCLUDE_TOMATO_ENTRYPOINT_HPP_1646142144
#define TOMATO_INCLUDE_TOMATO_ENTRYPOINT_HPP_1646142144

#ifdef __GNUC__

 #include "Application.hpp"
 #include "Logger.hpp"

// pch include memory

int main() {
  tmt::logger::init();
  TMT_CORE_CRITICAL("Core initialized {0}", 100);
  TMT_CORE_ERROR("Core initialized {0}", 200);
  TMT_CORE_WARN("Core initialized {0}", 300);
  TMT_CLIENT_INFO("Client initialized {0}", 400);
  TMT_CLIENT_DEBUG("Client initialized {0}", 500);

  std::unique_ptr<tmt::application> app { tmt::create_application() };
  app->run();
  return 0;
}

#endif

#endif
