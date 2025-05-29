#include "Application.h"
#include "Core/Logger.h"
#include "Game.h"

int main()
{

    Game game;
    if(!CreateGame(&game))
    {
        CFATAL("Couldn't Create Game Instance");
        return -1;
    }
    if(!game.Initialize || !game.Update || !game.Render)
    {
        CFATAL("Game Function Pointers must be assigned..!");
        return -2;
    }

    if(!ApplicationCreate(&game))
    {
        CFATAL("Something Went Wrong When Creating Application..!\n");
    }


    ApplicationRun();

    return 0;
}
