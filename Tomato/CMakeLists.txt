list(APPEND SOURCE_FILES
  src/Application.cpp
  src/Logger.cpp
)

list(APPEND HEADER_FILES
  include/Tomato/Application.h
  include/Tomato/EntryPoint.h
  include/Tomato/Logger.h

  src/Core.h
  src/events/Application.h
  src/events/Event.h
  src/events/Key.h
  src/events/Mouse.h
)

add_library(Tomato SHARED
  ${SOURCE_FILES}
  ${HEADER_FILES}
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(Tomato PUBLIC "-fvisibility=hidden")
endif()

list(APPEND THIRD_PARTY_INCLUDES
  vendor/spdlog/include
)

target_include_directories(Tomato
  PUBLIC ${THIRD_PARTY_INCLUDES} include
)

install(TARGETS Tomato LIBRARY DESTINATION Sandbox/lib)
