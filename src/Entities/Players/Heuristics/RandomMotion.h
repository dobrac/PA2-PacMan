#pragma once

#include "Motion.h"

class RandomMotion : public Motion {
public:
    bool chase(GameWorld &world, Player * ghost) override;
};
