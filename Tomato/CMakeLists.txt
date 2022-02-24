list(APPEND SOURCE_FILES
  src/Application.cpp
  src/Logger.cpp
)

list(APPEND HEADER_FILES
  include/Tomato/Application.h
  include/Tomato/EntryPoint.h
  include/Tomato/Logger.h

  src/Core.h
)

add_library(Tomato SHARED
  ${SOURCE_FILES}
  ${HEADER_FILES}
)

list(APPEND THIRD_PARTY_INCLUDES
  vendor/spdlog/include
)

target_include_directories(Tomato
  PUBLIC ${THIRD_PARTY_INCLUDES} include
)

install(TARGETS Tomato LIBRARY DESTINATION Sandbox/lib)