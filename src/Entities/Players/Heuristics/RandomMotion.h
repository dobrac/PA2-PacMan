#pragma once

#include "Motion.h"

/**
 * Class for Random Motion, overrides Motion methods
 */
class RandomMotion : public Motion {
public:
    bool chase(GameWorld &world, Player * ghost) override;
};
