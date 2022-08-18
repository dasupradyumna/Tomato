cmake_minimum_required(VERSION 3.16)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "CMake attempting in-source build!")
endif()

project(Tomato VERSION 1.0 LANGUAGES CXX)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
  set(CMAKE_CXX_EXTENSIONS FALSE)

  if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}"
      CACHE PATH "Installation path prefix" FORCE
    )
  endif()

  add_subdirectory(Tomato)
  add_subdirectory(Sandbox)

  if(CMAKE_EXPORT_COMPILE_COMMANDS)
    install(FILES "${CMAKE_BINARY_DIR}/compile_commands.json"
      DESTINATION "${CMAKE_SOURCE_DIR}/.vscode")
  endif()
endif()
