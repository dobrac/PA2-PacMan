#pragma once

#include "Motion.h"

class RandomMotion : public Motion {
public:
    bool chase(GameMap &map, Player * ghost) override;
};
