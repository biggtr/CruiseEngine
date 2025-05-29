#include "Application.h"
#include "Core/Logger.h"
int main()
{

    ApplicataionConfig appConfig;
    appConfig.x = 100;
    appConfig.y = 100;
    appConfig.width = 1280;
    appConfig.height = 720;
    appConfig.name = "Cruise Engine";

    if(!ApplicationCreate(&appConfig))
    {
        CFATAL("Something Went Wrong When Creating Application..!\n");
    }

    ApplicationRun();

    return 0;
}
