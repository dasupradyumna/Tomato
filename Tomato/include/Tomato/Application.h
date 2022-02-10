#pragma once

#include "../src/Core.h"

namespace TM
{
  class ENG_API Application
  {
  public:
    Application();
    virtual ~Application();

    void Run();
  };

  Application* CreateApplication();
}
