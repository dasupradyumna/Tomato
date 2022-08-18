#ifndef TOMATO_SRC_CORE_HPP_1646142246
#define TOMATO_SRC_CORE_HPP_1646142246

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

#define TWO_POW_(x) (1 << x)

#endif
