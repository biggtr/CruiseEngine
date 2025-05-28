#include "Logger.h"
#include <cstdio>
#include <stdarg.h>
#include "assert.h"


bool8 InitializeLogging()
{
    // TODO: Create a log file to spit logs in it
    return TRUE;
}

void Log(LogLevel level, const char* message, ...)
{
    const char* logLevel[6] = {"[FATAL]: ", "[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: "};
    char outMessage[64000];
    va_list args;
    va_start(args, message);
    vsnprintf(outMessage, sizeof(outMessage), message, args);
    va_end(args);

    char finalOutMessage[64000];
    sprintf(finalOutMessage, "%s%s\n", logLevel[(uint8)level], outMessage);

    printf("%s", finalOutMessage);
}
bool8 ShutdownLogging()
{
    
    return TRUE;
}
void ReportAssertionFailure(const char* expression, const char* message, const char* fileName, uint32 line)
{
    Log(LogLevel::FATAL,
        "Assertion Failure: '%s', message: '%s', in file '%s', line : %d",
        expression, message,
        fileName, line
       );
}
