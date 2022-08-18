#ifndef TOMATO_SRC_EVENTS_EVENT_HPP_1646142209
#define TOMATO_SRC_EVENTS_EVENT_HPP_1646142209

#include "../Core.hpp"

// pch include functional
// pch include string

namespace tmt
{
  enum class event_type : int {
    none,
    // window events
    window_close,
    window_focus,
    window_lost_focus,
    window_moved,
    window_resize,
    // application events
    application_render,
    application_tick,
    application_update,
    // keyboard events
    key_pressed,
    key_released,
    // mouse events
    mouse_button_pressed,
    mouse_button_released,
    mouse_moved,
    mouse_scrolled
  };

  enum event_category : int {
    none      = 0,
    app       = TWO_POW_(0),
    inp       = TWO_POW_(1),
    kbd       = TWO_POW_(2),
    mouse     = TWO_POW_(3),
    mouse_btn = TWO_POW_(4),
  };

  class API event {
  public:
    virtual event_type get_event_type() const = 0;
    virtual const char *get_name() const      = 0;
    virtual int get_category_flags() const    = 0;

    virtual std::string to_string() const { return get_name(); }

    inline bool is_in_category(event_category category) {
      return get_category_flags() & category;
    }

  protected:
    bool _handled = false;
  };

#define EVENT_DEBUG_METHODS(type)                     \
 static event_type get_static_type() { return type; } \
 virtual event_type get_event_type() const override { \
  return get_static_type();                           \
 }                                                    \
 virtual const char *get_name() const override { return #type; }

#define EVENT_CATEGORY(category) \
 virtual int get_category_flags() const override { return category; }

  inline std::ostream &operator<<(std::ostream &out, const event &ev) {
    return out << ev.to_string();
  }

  class event_dispatcher {
    template<typename _event_type>
    using event_func = std::function<bool(_event_type &)>;

  public:
    event_dispatcher(event &ev) : __ev { ev } { }

    template<typename _event_type>
    bool dispatch(event_func<_event_type> function) {
      if (__ev.get_event_type() == _event_type::get_static_type())
      {
        __ev._handled = function(*(static_cast<_event_type>(&__ev)));
        return true;
      }
      return false;
    }

  private:
    event &__ev;
  };
}

#endif
