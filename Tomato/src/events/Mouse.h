#ifndef TOMATO_SRC_EVENTS_MOUSE_H_1646142233
#define TOMATO_SRC_EVENTS_MOUSE_H_1646142233

#include "Event.h"

// pch include sstream

namespace tmt
{
  class API mouse_moved_event : public event
  {
  public:
    mouse_moved_event(float x, float y) : __mouse_x { x }, __mouse_y { y } { }

    inline float get_x() const { return __mouse_x; }
    inline float get_y() const { return __mouse_y; }

    std::string to_string() const override
    {
      std::stringstream out;
      out << "Event mouse_moved : [ " << __mouse_x << ", " << __mouse_y << " ]";
      return out.str();
    }

    EVENT_DEBUG_METHODS(event_type::mouse_moved)
    EVENT_CATEGORY(inp | mouse)

  private:
    float __mouse_x;
    float __mouse_y;
  };

  class API mouse_scrolled_event : public event
  {
  public:
    mouse_scrolled_event(float x, float y) : __offset_x { x }, __offset_y { y } { }

    inline float get_offset_x() const { return __offset_x; }
    inline float get_offset_y() const { return __offset_y; }

    std::string to_string() const override
    {
      std::stringstream out;
      out << "Event mouse_scrolled : [ " << __offset_x << ", " << __offset_y << " ]";
      return out.str();
    }

    EVENT_DEBUG_METHODS(event_type::mouse_scrolled)
    EVENT_CATEGORY(inp | mouse)

  private:
    float __offset_x;
    float __offset_y;
  };

  class mouse_button_event : public event
  {
  public:
    inline int get_mouse_button() const { return _button; }

    EVENT_CATEGORY(inp | mouse_btn)

  protected:
    int _button;

    mouse_button_event(int button) : _button { button } { }
  };

  class API mouse_button_pressed_event : public mouse_button_event
  {
  public:
    mouse_button_pressed_event(int button) : mouse_button_event { button } { }

    std::string to_string() const override
    {
      std::stringstream out;
      out << "Event mouse_button_pressed : " << _button;
      return out.str();
    }

    EVENT_DEBUG_METHODS(event_type::mouse_button_pressed)
  };

  class API mouse_button_released_event : public mouse_button_event
  {
  public:
    mouse_button_released_event(int button) : mouse_button_event { button } { }

    std::string to_string() const override
    {
      std::stringstream out;
      out << "Event mouse_button_released : " << _button;
      return out.str();
    }

    EVENT_DEBUG_METHODS(event_type::mouse_button_released)
  };
}

#endif
