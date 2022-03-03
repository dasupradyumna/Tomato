#ifndef TOMATO_SRC_EVENTS_KEY_H_1646142223
#define TOMATO_SRC_EVENTS_KEY_H_1646142223

#include "Event.h"

// pch include sstream

namespace tmt
{
  class key_event : public event
  {
  public:
    inline int get_key_code() const { return __key_code; }

    EVENT_CATEGORY(inp | kbd)

  protected:
    int __key_code;

    key_event(int key_code) : __key_code { key_code } { }
  };

  class API key_pressed_event : public key_event
  {
  public:
    key_pressed_event(int key_code, int repeat_count)
      : key_event { key_code }, __repeat_count { repeat_count }
    { }

    inline int get_repeat_count() const { return __repeat_count; }

    std::string to_string() const override
    {
      std::stringstream out;
      out << "Event key_pressed_event : " << __key_code << " [ " << __repeat_count << " repeats ]";
      return out.str();
    }

    EVENT_DEBUG_METHODS(event_type::key_pressed)

  private:
    int __repeat_count;
  };

  class API key_released_event : public key_event
  {
  public:
    key_released_event(int key_code) : key_event { key_code } { }

    std::string to_string() const override
    {
      std::stringstream out;
      out << "Event key_released_event : " << __key_code;
      return out.str();
    }

    EVENT_DEBUG_METHODS(event_type::key_released)
  };
}

#endif
