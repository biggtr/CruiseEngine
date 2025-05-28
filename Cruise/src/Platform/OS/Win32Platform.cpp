#ifdef CPLATFORM_WINDOWS
#include "Platform.h"
#include <windows.h>

struct PlatfromWindow
{
    HWND WindowHandle;
    HINSTANCE hInstance;
};


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

}
void PlatformMessageHandler();

void PlatfromStartup(PlatfromWindow &window, int32 x, int32 y, uint32 width, uint32 height)
{
    window.hInstance = GetModuleHandleA(0);
    HICON icon = LoadIcon(window.hInstance, "EngineIcon")
    // create windows class to specify what type of window it is
    WNDCLASS windowClass = {}; 
    windowClass.lpfnWndProc = WindowProc;
    wc.hInstance = window.hInstance;
    wc.lpszClassName = "CruiseEngine";
    RegisterClassA(&windowClass);
    window.WindowHandle = CreateWindowEx(
        0,                              
        CLASS_NAME,                     
        L"CruiseEngine",    
        WS_OVERLAPPEDWINDOW,            
        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        window.hInstance,  // Instance handle
        NULL        // Additional application data
        );

    if (window.WindowHandle == NULL)
    {
        return -1;
    }
    ShowWindow(window.WindowHandle, SW_SHOWNORMAL);
}
#endif
