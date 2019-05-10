#include <utility>

#pragma once

#include "Motion.h"

class AheadMotion : public Motion {
public:
    bool chase(GameWorld &world, Player *ghost) override;
};
