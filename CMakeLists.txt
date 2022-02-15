cmake_minimum_required(VERSION 3.16)

project(Tomato VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}"
    CACHE PATH "Installation path prefix" FORCE
  )
endif()

add_subdirectory(Tomato)
add_subdirectory(Sandbox)
