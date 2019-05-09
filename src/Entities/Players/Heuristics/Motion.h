#pragma once

#include "../Player.h"
#include "../PacMan.h"
#include <memory>

class GameWorld;

class Motion {
public:
    virtual bool chase(GameWorld &world, Player * ghost) = 0;
};
