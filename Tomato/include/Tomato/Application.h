#ifndef INCLUDE_TOMATO_APPLICATION_H_INCLUDED
#define INCLUDE_TOMATO_APPLICATION_H_INCLUDED

#include "../src/Core.h"

namespace tmt
{
  class API application
  {
  public:
    application();
    virtual ~application();

    void run();
  };

  application* create_application();
}

#endif
