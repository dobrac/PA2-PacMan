#include <utility>

#pragma once

#include "Motion.h"

/**
 * Class for Follow Motion, overrides Motion methods
 */
class FollowMotion : public Motion {
public:
    bool chase(GameWorld &world, Player *ghost) override;
};
