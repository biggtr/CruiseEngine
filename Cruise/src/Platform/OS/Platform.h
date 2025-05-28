#pragma once 
#include "Core/Defines.h"


struct PlatformWindow;

bool8 PlatfromStartup(PlatformWindow** window, int32 x, int32 y, uint32 width, uint32 height);
void PlatformEventLoop(PlatformWindow& window);
void PlatformShutdown(PlatformWindow** window);
