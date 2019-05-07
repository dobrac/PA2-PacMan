#pragma once

#include "../../../Game/GameMap.h"
#include "../Player.h"

class Motion {
public:
    virtual bool chase(GameMap &map, Player * ghost) = 0;
};
