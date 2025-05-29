#include "Platform.h"
#include "Core/Logger.h"
#include "Core/assert.h"
#include <stdlib.h>

#ifdef CPLATFORM_LINUX
#include <X11/X.h>
#include <stdlib.h>
#include <X11/Xlib.h>


#define KEY_ESC 9
#define KEY_W 25
#define KEY_A 38
#define KEY_S 39
#define KEY_D 40

struct Platform
{
    Display* display;
    Window windowDisplay;
    XEvent event;
    int32 screen;
};

bool8 PlatfromStartup(Platform** outWindow, int32 x, int32 y, uint32 width, uint32 height)
{
    *outWindow = (Platform*)malloc(sizeof(Platform));
    Platform* window = *outWindow;

    window->display = XOpenDisplay(NULL);
    CASSERT_MSG(window->display, "Connection hasnt been established correctly\n");
    window->screen = DefaultScreen(window->display);
    CINFO("the width of our screen is : %d", DisplayWidth(window->display, window->screen));
    CINFO("the height of our screen is : %d", DisplayHeight(window->display, window->screen));
    window->windowDisplay = XCreateSimpleWindow(window->display, 
                        RootWindow(window->display, window->screen),
                        x, y,
                        width, height,
                        0,
                        0,
                        WhitePixel(window->display, window->screen)
                       ); 
    
    // making the window visable on the screen 
    XMapWindow(window->display, window->windowDisplay); 

    // selecting the events i want to listen to 
    XSelectInput(window->display, window->windowDisplay,
            KeyPressMask | KeyReleaseMask |
            ButtonPressMask | ButtonReleaseMask | 
            PointerMotionMask | ExposureMask
            );
    

    return TRUE;

}
bool8 PlatformEventLoop(Platform* window)
{
    while(XPending(window->display) > 0)
    {
        XNextEvent(window->display, &window->event);
        
        switch (window->event.type) 
        {
            case KeyPress:
                switch (window->event.xkey.keycode) 
                {
                    case KEY_ESC:
                        CINFO("escape key pressed");
                        break;
                    case KEY_W:
                        CINFO("W key pressed");
                        break;
                    case KEY_A:
                        CINFO("A key pressed");
                        break;
                    case KEY_S:
                        CINFO("S key pressed");
                        break;
                    case KEY_D:
                        CINFO("D key pressed");
                        break;
                }                
                break;
        }
    }
    XFlush(window->display);
    return TRUE;
}
bool8 PlatformShutdown(Platform** platform)
{
    Platform* outPlatform = *platform;
    if(outPlatform)
    {
        XDestroyWindow(outPlatform->display, outPlatform->windowDisplay);
        XCloseDisplay(outPlatform->display);
        free(outPlatform);
    }
    return TRUE;
}
#endif
