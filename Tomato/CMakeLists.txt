list(APPEND SOURCE_FILES
  src/Application.cpp
  src/Logger.cpp
)

list(APPEND HEADER_FILES
  include/Tomato/Application.hpp
  include/Tomato/EntryPoint.hpp
  include/Tomato/Logger.hpp

  src/Core.hpp
  src/events/Application.hpp
  src/events/Event.hpp
  src/events/Key.hpp
  src/events/Mouse.hpp
)

list(APPEND THIRD_PARTY_INCLUDES
  vendor/spdlog/include
)

add_library(Tomato SHARED
  ${SOURCE_FILES}
  ${HEADER_FILES}
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(Tomato PUBLIC "-fvisibility=hidden" "-H")
endif()

target_include_directories(Tomato
  PUBLIC ${THIRD_PARTY_INCLUDES} include
)

target_precompile_headers(Tomato PUBLIC std-pch.hpp spdlog-pch.hpp)

install(TARGETS Tomato LIBRARY DESTINATION Sandbox/lib)
