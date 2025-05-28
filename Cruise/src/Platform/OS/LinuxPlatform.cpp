#include "Core/assert.h"
#include <X11/X.h>
#include <stdlib.h>
#include "Platform.h"
#include <X11/Xlib.h>

#ifdef CPLATFORM_LINUX
struct PlatformWindow
{
    Display* display;
    Window windowDisplay;
    XEvent event;
    int32 screen;
};

bool8 PlatfromStartup(PlatformWindow** outWindow, int32 x, int32 y, uint32 width, uint32 height)
{
    *outWindow = (PlatformWindow*)malloc(sizeof(PlatformWindow));
    PlatformWindow* window = *outWindow;

    window->display = XOpenDisplay(":0");
    window->screen = DefaultScreen(window->display);
    Window rootWindow = RootWindow(window->display, window->screen);
    CASSERT_MSG(window->display, "Connection hasnt been established correctly\n");
    window->windowDisplay = XCreateSimpleWindow(window->display, 
                        RootWindow(window->display, window->screen),
                        x, y,
                        width, height,
                        1,
                        BlackPixel(window->display, window->screen), 
                        WhitePixel(window->display, window->screen)
                       ); 
    XSelectInput(window->display, window->windowDisplay, ExposureMask | KeyPressMask);
    XMapWindow(window->display, window->windowDisplay);

    return TRUE;

}
void PlatformEventLoop(PlatformWindow& window)
{
    while(TRUE)
    {
        XNextEvent(window.display, &window.event);
        if(window.event.type == Expose)
        {
            XFillRectangle(window.display, window.windowDisplay, DefaultGC(window.display, window.screen),
                          20, 20, 100, 100);
        }
        if(window.event.type == KeyPress)
        {
            break;
        }
    }

}
void PlatformShutdown(PlatformWindow* window)
{
    if(window)
    {
        XDestroyWindow(window->display, window->windowDisplay);
        XCloseDisplay(window->display);
    }
}

#endif
