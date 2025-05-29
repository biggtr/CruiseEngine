#include "TestGame.h"
#include "Core/Logger.h"

bool8 GameInitialize(struct Game* gameInstance)
{
    CINFO("Game Initialized...!");
    return TRUE;
}
bool8 GameUpdate(struct Game* gameInstance, float64 deltaTime)
{
    return TRUE;
}
bool8 GameRender(struct Game* gameInstance)
{
    return TRUE;
}
