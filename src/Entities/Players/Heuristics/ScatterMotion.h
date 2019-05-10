#pragma once

#include "Motion.h"

class ScatterMotion : public Motion {
public:
    bool chase(GameWorld &world, Player *ghost) override;
};
