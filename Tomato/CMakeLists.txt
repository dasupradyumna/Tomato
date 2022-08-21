list(APPEND SOURCE_FILES
  src/Application.cpp
  src/Logger.cpp

  src/platform/WindowLinux.cpp
)

list(APPEND HEADER_FILES
  include/Tomato/Application.hpp
  include/Tomato/EntryPoint.hpp
  include/Tomato/Logger.hpp

  src/Core.hpp
  src/Window.hpp
  src/events/Application.hpp
  src/events/Event.hpp
  src/events/Key.hpp
  src/events/Mouse.hpp
  src/platform/WindowLinux.hpp
)

add_library(Tomato SHARED
  ${SOURCE_FILES}
  ${HEADER_FILES}
)

find_package(OpenGL REQUIRED)
add_subdirectory(vendor/glfw)

target_link_libraries(Tomato PRIVATE glfw OpenGL::GL)

list(APPEND THIRD_PARTY_INCLUDES
  vendor/glfw/include
  vendor/spdlog/include
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(Tomato PRIVATE "-fvisibility=hidden" "-H")
endif()

target_compile_definitions(Tomato PRIVATE "$<$<CONFIG:Debug>:TMT_ENABLE_ASSERTS>")

target_include_directories(Tomato
  PUBLIC ${THIRD_PARTY_INCLUDES} include
)

target_precompile_headers(Tomato PUBLIC std-pch.hpp spdlog-pch.hpp)

install(TARGETS Tomato LIBRARY DESTINATION Sandbox/lib)
