#include "Tomato/Application.h"
#include "Tomato/Logger.h"

#include "events/Application.h"

namespace tmt
{
  application::application() { }

  application::~application() { }

  void application::run()
  {
    window_resize_event Ev { 1280, 720 };
    if (Ev.is_in_category(app)) TMT_CORE_TRACE(Ev);
    while (true) { }
  }
}
