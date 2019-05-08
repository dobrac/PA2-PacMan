#pragma once

#include "../Player.h"
#include "../PacMan.h"
#include "../../../Game/GameWorld.h"

class Motion {
public:
    virtual bool chase(GameWorld &world, Player * ghost) = 0;
};
