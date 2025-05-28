#include <X11/Xlib.h>
#include <cstdlib>
#include <stdio.h>
#include "Core/Logger.h"
#include "Platform/OS/Platform.h"
int main()
{

    PlatformWindow* window = nullptr;    
    PlatfromStartup(&window, 100, 100, 1280, 720);
    PlatformEventLoop(*window);


    CFATAL("TEST: %.2f",3.14f);
    CERROR("TEST: %.2f",3.14f);
    CTRACE("TEST: %.2f",3.14f);
    CDEBUG("TEST: %.2f",3.14f);

    return 0;
}
