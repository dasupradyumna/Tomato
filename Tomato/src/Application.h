#pragma once

#include "Core.h"

namespace TM
{
  class ENG_API Application
  {
  public:
    Application();
    virtual ~Application();

    void Run();
  };

  Application *CreateApplication();
}
