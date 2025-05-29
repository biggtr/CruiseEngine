#pragma once
#include "Defines.h"

struct Game;
struct ApplicataionConfig
{
    int32 x;
    int32 y;
    uint32 width;
    uint32 height;
    char* name;
};


bool8 ApplicationCreate(Game* gameInstance);

bool8 ApplicationRun();
