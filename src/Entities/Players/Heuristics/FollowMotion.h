#include <utility>

#pragma once

#include "Motion.h"

class FollowMotion : public Motion {
public:
    bool chase(GameWorld &world, Player *ghost) override;
};
