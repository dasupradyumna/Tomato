#include "Tomato/Application.hpp"

#include <GLFW/glfw3.h>

namespace tmt
{
  application::application()
    : __window { std::unique_ptr<window>(window::create()) }, __running { true }
  { }

  application::~application() { }

  void application::run()
  {
    while (__running) {
      glClearColor(0, 0.5, 0, 1);
      glClear(GL_COLOR_BUFFER_BIT);
      __window->on_update();
    }
  }
}
