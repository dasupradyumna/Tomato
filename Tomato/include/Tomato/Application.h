#ifndef TOMATO_INCLUDE_TOMATO_APPLICATION_H_1646142124
#define TOMATO_INCLUDE_TOMATO_APPLICATION_H_1646142124

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
