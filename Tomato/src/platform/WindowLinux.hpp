#ifndef TOMATO_SRC_PLATFORM_WINDOWLINUX_HPP_1660907233
#define TOMATO_SRC_PLATFORM_WINDOWLINUX_HPP_1660907233

#include "../Window.hpp"

#include <GLFW/glfw3.h>

// pch string

namespace tmt
{
  class window_lin : public window {
  private:
    struct window_data {
      std::string title;
      unsigned int width, height;
      bool vsync;
      event_callback_func event_callback;
    };

  public:
    window_lin(const window_properties &props);
    virtual ~window_lin();

    void on_update() override;

    unsigned int get_width() const override { return __data.width; }

    unsigned int get_height() const override { return __data.height; }

    void set_event_callback(const event_callback_func &callback) override
    {
      __data.event_callback = callback;
    }

    void set_vsync(const bool enabled) override;

    bool is_vsync() const override { return __data.vsync; }

  private:
    virtual void init(const window_properties &props);
    virtual void shutdown();

    GLFWwindow *__window;
    window_data __data;
  };
}

#endif
