#pragma once 
#include "Defines.h"
#include <cstdio>
#include <system_error>

#define CASSERTIONS_ENABLED

#ifdef CASSERTIONS_ENABLED

#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

void ReportAssertionFailure(const char* expression, const char* message, const char* fileName, uint32 line);

#define CASSERT(expr)                                           \
{                                                               \
    if(expr)                                                    \
    {}                                                          \
    else                                                        \
    {                                                           \
        ReportAssertionFailure(#expr, "", __FILE__, __LINE__);  \
        debugBreak();                                           \
    }                                                           \
}                                                               \

#define CASSERT_MSG(expr, message)                              \
{                                                               \
    if(expr)                                                    \
    {}                                                          \
    else                                                        \
    {                                                           \
        ReportAssertionFailure(#expr, message, __FILE__, __LINE__);  \
        debugBreak();                                           \
    }                                                           \
}                                                               \

#ifdef _DEBUG
#define CASSERT_DEBUG(expr)
{                                                               \
    if(expr)                                                    \
    {}                                                          \
    else                                                        \
    {                                                           \
        ReportAssertionFailure(#expr, message, __FILE__, __LINE__);  \
        debugBreak();                                           \
    }                                                           \
}                                                               \
#else
#define CASSERT_DEBUG(expr) // do nothing
#endif

#else
// if CASSERTIONS_ENABLED false do nothing
#define CASSERT(expr) 
#define CASSERT_MSG(expr, message)
#define CASSERT_DEBUG(expr) 
#endif
