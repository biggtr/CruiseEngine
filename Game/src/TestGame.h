#pragma once 
#include "Platform/OS/Platform.h"


bool8 GameInitialize(struct Game* gameInstance);
bool8 GameUpdate(struct Game* gameInstance, float64 deltaTime);
bool8 GameRender(struct Game* gameInstance);
