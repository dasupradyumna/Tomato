#ifndef SRC_CORE_H_INCLUDED
#define SRC_CORE_H_INCLUDED

#ifdef __GNUC__
 #ifdef _WIN32
  #ifdef WIN_BUILD
   #define API __attribute__((dllexport))
  #else
   #define API __attribute__((dllimport))
  #endif
 #else
  #define API __attribute__((visibility("default")))
 #endif
#else
 #error Engine built only for GCC
#endif

#endif
