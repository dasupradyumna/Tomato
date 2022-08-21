#ifndef TOMATO_SRC_WINDOW_HPP_1660898073
#define TOMATO_SRC_WINDOW_HPP_1660898073

#include "Core.hpp"
#include "events/Event.hpp"

// pch string
// pch functional

namespace tmt
{
  struct window_properties {
    std::string title;
    unsigned int width;
    unsigned int height;

    window_properties(const std::string &title = "Tomato",
      const unsigned int width = 1280, const unsigned int height = 720)
      : title { title }, width { width }, height { height }
    { }
  };

  class API window {
  public:
    using event_callback_func = std::function<void(event &)>;

    virtual ~window() { }

    virtual void on_update()                = 0;
    virtual unsigned int get_width() const  = 0;
    virtual unsigned int get_height() const = 0;

    virtual void set_event_callback(const event_callback_func &callback) = 0;
    virtual void set_vsync(const bool enabled)                           = 0;
    virtual bool is_vsync() const                                        = 0;

    static window *create(const window_properties &props = window_properties {});
  };
}

#endif
