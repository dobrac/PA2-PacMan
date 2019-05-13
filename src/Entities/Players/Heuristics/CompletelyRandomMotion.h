#pragma once

#include "Motion.h"

/**
 * Class for Completely Random Motion, overrides Motion methods
 */
class CompletelyRandomMotion : public Motion {
public:
    bool chase(GameWorld &world, Player * ghost) override;
};
