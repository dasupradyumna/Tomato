#ifndef INCLUDE_TOMATO_ENTRYPOINT_H_INCLUDED
#define INCLUDE_TOMATO_ENTRYPOINT_H_INCLUDED

#ifdef __GNUC__

 #include "Application.h"
 #include "Logger.h"

 #include <memory>

int main()
{
  tmt::logger::init();
  CORE_CRITICAL("Core initialized {0}", 100);
  CORE_ERROR("Core initialized {0}", 200);
  CORE_WARN("Core initialized {0}", 300);
  CLIENT_INFO("Client initialized {0}", 400);
  CLIENT_DEBUG("Client initialized {0}", 500);
  CLIENT_TRACE("Client initialized {0}", 600);

  std::unique_ptr<tmt::application> app { tmt::create_application() };
  app->run();
  return 0;
}

#endif

#endif
