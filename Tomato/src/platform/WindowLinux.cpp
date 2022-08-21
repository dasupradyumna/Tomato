#include "WindowLinux.hpp"

#include "../Core.hpp"

#include <Tomato/Logger.hpp>

namespace tmt
{
  static bool is_glfw_initialized = false;

  window *window::create(const window_properties &props)
  {
    return new window_lin { props };
  }

  window_lin::window_lin(const window_properties &props) : __data {}, __window { nullptr }
  {
    init(props);
  }

  window_lin::~window_lin() { shutdown(); }

  void window_lin::init(const window_properties &props)
  {
    __data.title  = props.title;
    __data.height = props.height;
    __data.width  = props.width;
    TMT_CORE_INFO(
      "Creating window : {0} [{1}, {2}]", props.title, props.width, props.height);

    if (!is_glfw_initialized) {
      bool success { static_cast<bool>(glfwInit()) };
      TMT_CORE_ASSERT(success, "Could not initialize GLFW!");
      is_glfw_initialized = true;
    }

    __window = glfwCreateWindow(
      __data.width, __data.height, __data.title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(__window);
    glfwSetWindowUserPointer(__window, &__data);
    set_vsync(true);
  }

  void window_lin::shutdown() { glfwDestroyWindow(__window); }

  void window_lin::on_update()
  {
    glfwPollEvents();
    glfwSwapBuffers(__window);
  }

  void window_lin::set_vsync(const bool enabled)
  {
    glfwSwapInterval(enabled);
    __data.vsync = enabled;
  }
}
