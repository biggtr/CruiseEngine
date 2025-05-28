#pragma once 

#include <cstdint>

// Unsigned int types
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

// Signed int types
typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;


typedef int8_t  bool8;
typedef int32_t bool32; 

// Floating point types
typedef float float32;
typedef double float64;

#if defined (__clang__) || defined (__gcc__)
#define STATIC_ASSERT _Static_assert 
#else
#define STATIC_ASSERT static_assert
#endif


STATIC_ASSERT(sizeof(int8)  == 1, "Size of int8 should be 1 byte");
STATIC_ASSERT(sizeof(int16) == 2, "Size of int16 should be 2 byte");
STATIC_ASSERT(sizeof(int32) == 4, "Size of int32 should be 4 byte");
STATIC_ASSERT(sizeof(int64) == 8, "Size of int64 should be 8 byte");

STATIC_ASSERT(sizeof(uint8)  == 1, "Size of uint8  should be 1 byte");
STATIC_ASSERT(sizeof(uint16) == 2, "Size of uint16 should be 2 byte");
STATIC_ASSERT(sizeof(uint32) == 4, "Size of uint32 should be 4 byte");
STATIC_ASSERT(sizeof(uint64) == 8, "Size of uint64 should be 8 byte");

STATIC_ASSERT(sizeof(float32) == 4, "Size of float32 should be 4 byte");
STATIC_ASSERT(sizeof(float64) == 8, "Size of float64 should be 8 byte");

#define TRUE 1
#define FALSE 0 


// Platform (C --> for Cruise)

// Windows
#if defined(WIN32) || defined(__WIN32) || defined(__WIN32__)
#define CPLATFORM_WINDOW 1
#ifndef _WIN64
#error "The system is not 64-bit windows "
#endif

// Linux 
#elif defined(__linux__) || defined(__gnu_linux__)
#define CPLATFORM_LINUX 1

#endif
