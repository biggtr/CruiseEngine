#pragma once
#include "Defines.h"

struct ApplicataionConfig
{
    int32 x;
    int32 y;
    uint32 width;
    uint32 height;
    char* name;
};


bool8 ApplicationCreate(ApplicataionConfig* appConfig);

bool8 ApplicationRun();
