#pragma once 
#include "Core/Application.h"

extern bool8 CreateGame(Game* outGame);
struct Game
{
    ApplicataionConfig appConfig;

    bool8 (*Initialize) (struct Game* gameInstance);
    bool8 (*Update) (struct Game* gameInstance, float64 deltaTime);
    bool8 (*Render) (struct Game* gameInstance);
};
