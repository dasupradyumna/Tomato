#ifndef TOMATO_SRC_CORE_HPP_1646142246
#define TOMATO_SRC_CORE_HPP_1646142246

// pch signal.h

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
 #define debug_breakpoint raise(SIGINT)
#else
 #error Engine built only for GCC
#endif

#ifdef TMT_ENABLE_ASSERTS
 #define TMT_CLIENT_ASSERT(x, ...)                            \
  {                                                           \
   if (!(x)) {                                                \
    TMT_CLIENT_ERROR("Assertion failed! : {0}", __VA_ARGS__); \
    debug_breakpoint;                                         \
   }                                                          \
  }
 #define TMT_CORE_ASSERT(x, ...)                            \
  {                                                         \
   if (!(x)) {                                              \
    TMT_CORE_ERROR("Assertion failed! : {0}", __VA_ARGS__); \
    debug_breakpoint;                                       \
   }                                                        \
  }
#else
 #define TMT_CLIENT_ASSERT(x, ...)
 #define TMT_CORE_ASSERT(x, ...)
#endif

#define TWO_POW_(x) (1 << x)

#endif
