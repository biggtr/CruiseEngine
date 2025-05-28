#pragma once 

#include "Defines.h"

enum class LogLevel: uint8
{
    FATAL = 0,
    ERROR = 1,
    WARN = 2,
    INFO = 3,
    DEBUG = 4,
    TRACE = 5,
};
bool8 InitializeLogging();
bool8 ShutdownLogging();
void Log(LogLevel level, const char* message, ...);





#define CFATAL(message, ...) Log(LogLevel::FATAL, message, __VA_ARGS__);
#define CERROR(message, ...) Log(LogLevel::ERROR, message, __VA_ARGS__);
#define CTRACE(message, ...) Log(LogLevel::TRACE, message, __VA_ARGS__);
#define CDEBUG(message, ...) Log(LogLevel::DEBUG, message, __VA_ARGS__);
#define CWARN(message, ...)  Log(LogLevel::WARN, message, __VA_ARGS__);
#define CINFO(message, ...)  Log(LogLevel::INFO, message, __VA_ARGS__);
