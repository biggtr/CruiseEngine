// #include <X11/Xlib.h>
// #include <stdio.h>
// #include "Core/Logger.h"
// #include "Core/assert.h"
// int main()
// {
//     Display* XConnection = XOpenDisplay(":0");
//     if(!XConnection)
//     {
//         printf("Connection hasnt been established correctly\n");
//         return -1;
//     } 
//     int numOfScreens = XScreenCount(XConnection);
//     printf("Display connection is esablished correctly and num of screens is %d \n", numOfScreens);
//
//
//     CFATAL("TEST: %.2f",3.14f);
//     CERROR("TEST: %.2f",3.14f);
//     CTRACE("TEST: %.2f",3.14f);
//     CDEBUG("TEST: %.2f",3.14f);
//     CASSERT(FALSE);
//
//     return 0;
// }
