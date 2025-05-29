#pragma once 
#include "Core/Defines.h"


struct Platform;

bool8 PlatfromStartup(Platform** platform, int32 x, int32 y, uint32 width, uint32 height);
bool8 PlatformEventLoop(Platform* platform);
bool8 PlatformShutdown(Platform** platform);
