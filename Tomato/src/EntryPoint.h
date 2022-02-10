#pragma once

#ifdef __GNUC__

#include "Application.h"

// extern TM::Application* TM::CreateApplication();

int main()
{
  auto app = TM::CreateApplication();
  app->Run();
  delete app;
  return 0;
}

#endif
