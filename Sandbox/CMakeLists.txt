list(APPEND SOURCE_FILES
  src/main.cpp
)

list(APPEND HEADER_FILES)

add_executable(Test
  ${SOURCE_FILES}
  ${HEADER_FILES}
)

target_link_libraries(Test PRIVATE Tomato)

set_target_properties(Test PROPERTIES
  BUILD_WITH_INSTALL_RPATH FALSE
  INSTALL_RPATH "$ORIGIN/../lib"
)

install(TARGETS Test RUNTIME DESTINATION Sandbox/bin)
