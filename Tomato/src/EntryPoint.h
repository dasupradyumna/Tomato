#pragma once

#ifdef __GNUC__

#include "Application.h"
#include "Logger.h"

#include <memory>

int main()
{
  TM::Logger::Init();
  CORE_CRITICAL("Core initialized {0}", 100);
  CORE_ERROR("Core initialized {0}", 200);
  CORE_WARN("Core initialized {0}", 300);
  CLIENT_INFO("Client initialized {0}", 400);
  CLIENT_DEBUG("Client initialized {0}", 500);
  CLIENT_TRACE("Client initialized {0}", 600);

  std::unique_ptr<TM::Application> app{TM::CreateApplication()};
  app->Run();
  return 0;
}

#endif
