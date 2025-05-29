#include "Application.h"
#include "Game.h"
#include "Core/Logger.h"
#include "Platform/OS/Platform.h"

struct Application 
{
    Game* gameInstance;
    bool8 IsRunning;
    bool8 IsSuspended;
    Platform* platform;
    uint16 width;
    uint16 height;
    float64 lastTime;
};

static bool8 Initialized = FALSE;
static Application application;

bool8 ApplicationCreate(Game* gameInstance)
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

    application.gameInstance = gameInstance;

    application.gameInstance->Initialize(gameInstance);
    application.IsRunning = TRUE;
    application.IsSuspended = FALSE;


    if(!PlatfromStartup(&application.platform,
                application.gameInstance->appConfig.x,
                application.gameInstance->appConfig.y,
                application.gameInstance->appConfig.width,
                application.gameInstance->appConfig.height
                ))
    {
        return FALSE;
    }
    if(!application.gameInstance->Initialize(application.gameInstance))
    {
        CDEBUG("Couldn't Initialize The Game..!");
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
        if(application.IsSuspended)
        {
            
        }
    }
    application.IsRunning = FALSE;
    PlatformShutdown(&application.platform);
    return TRUE;
}

