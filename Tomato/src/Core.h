#pragma once

#ifdef __GNUC__
 #ifdef _WIN32
  #ifdef WIN_BUILD
   #define ENG_API __attribute__((dllexport))
  #else
   #define ENG_API __attribute__((dllimport))
  #endif
 #else
  #define ENG_API __attribute__((visibility("default")))
 #endif
#else
 #error Engine built only for GCC
#endif
