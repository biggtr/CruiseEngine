#include "TestGame.h"
#include "Core/Defines.h"
#include <Core/Game.h>



bool8 CreateGame(Game *outGame)
{
    outGame->appConfig.x = 100;
    outGame->appConfig.y = 100;
    outGame->appConfig.width = 1280;
    outGame->appConfig.height = 720;
    outGame->appConfig.name = "Cruise Engine";
    outGame->Initialize = GameInitialize;
    outGame->Update = GameUpdate;
    outGame->Render = GameRender;

    return TRUE;
}
