#ifndef TOMATO_INCLUDE_TOMATO_APPLICATION_HPP_1646142124
#define TOMATO_INCLUDE_TOMATO_APPLICATION_HPP_1646142124

#include "../src/Core.hpp"
#include "../src/Window.hpp"

// pch memory

namespace tmt
{
  class API application {
  public:
    application();
    virtual ~application();

    void run();

  private:
    std::unique_ptr<window> __window;
    bool __running;
  };

  application *create_application();
}

#endif
