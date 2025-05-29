#include "Application.h"
#include "Core/Logger.h"
#include "Platform/OS/Platform.h"

struct Application 
{
    bool8 IsRunning;
    bool8 IsSuspended;
    Platform* platform;
    uint16 width;
    uint16 height;
    float64 lastTime;
};

static bool8 Initialized = FALSE;
static Application application;

bool8 ApplicationCreate(ApplicataionConfig* appConfig)
{
    if(Initialized)
    {
        CERROR("You Cannot Create More Than One App At The SAME TIME..!");
        return FALSE;
    }

    // Initialize Subsystems in here
    InitializeLogging();
    CFATAL("TEST: %.2f",3.14f);
    CERROR("TEST: %.2f",3.14f);
    CTRACE("TEST: %.2f",3.14f);
    CDEBUG("TEST: %.2f",3.14f);

    application.IsRunning = TRUE;
    application.IsSuspended = FALSE;

    if(!PlatfromStartup(&application.platform, appConfig->x, appConfig->y, appConfig->width, appConfig->height))
    {
        return FALSE;
    }

    Initialized = TRUE;
    return TRUE;
}

bool8 ApplicationRun()
{
    while(application.IsRunning)
    {
        if(!PlatformEventLoop(application.platform))
        {
            CFATAL("Something Went Wrong with PlatformEventLoop");
            application.IsRunning = FALSE;
            application.IsSuspended = TRUE;
        }
    }
    application.IsRunning = FALSE;
    PlatformShutdown(&application.platform);
    return TRUE;
}

