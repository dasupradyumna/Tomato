#ifndef TOMATO_SRC_EVENTS_APPLICATION_HPP_1646142182
#define TOMATO_SRC_EVENTS_APPLICATION_HPP_1646142182

#include "Event.hpp"

// pch sstream

namespace tmt
{
  class API window_close_event : public event {
  public:
    window_close_event() { }

    EVENT_DEBUG_METHODS(event_type::window_close)
    EVENT_CATEGORY(app)
  };

  class API window_focus_event : public event {
  public:
    window_focus_event() { }

    EVENT_DEBUG_METHODS(event_type::window_focus)
    EVENT_CATEGORY(app)
  };

  class API window_lost_focus_event : public event {
  public:
    window_lost_focus_event() { }

    EVENT_DEBUG_METHODS(event_type::window_lost_focus)
    EVENT_CATEGORY(app)
  };

  class API window_moved_event : public event {
  public:
    window_moved_event() { }

    EVENT_DEBUG_METHODS(event_type::window_moved)
    EVENT_CATEGORY(app)
  };

  class API window_resize_event : public event {
  public:
    window_resize_event(unsigned int width, unsigned int height)
      : __width { width }, __height { height }
    { }

    inline unsigned int get_width() const { return __width; }

    inline unsigned int get_height() const { return __height; }

    std::string to_string() const override
    {
      std::stringstream out;
      out << "Event window_resize : [ " << __width << ", " << __height << " ]";
      return out.str();
    }

    EVENT_DEBUG_METHODS(event_type::window_resize)
    EVENT_CATEGORY(app)

  private:
    unsigned int __width;
    unsigned int __height;
  };

  class API application_render_event : public event {
  public:
    application_render_event() { }

    EVENT_DEBUG_METHODS(event_type::application_render)
    EVENT_CATEGORY(app)
  };

  class API application_tick_event : public event {
  public:
    application_tick_event() { }

    EVENT_DEBUG_METHODS(event_type::application_tick)
    EVENT_CATEGORY(app)
  };

  class API application_update_event : public event {
  public:
    application_update_event() { }

    EVENT_DEBUG_METHODS(event_type::application_update)
    EVENT_CATEGORY(app)
  };

}

#endif
