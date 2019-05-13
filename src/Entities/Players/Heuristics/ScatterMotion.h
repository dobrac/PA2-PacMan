#pragma once

#include "Motion.h"

/**
 * Class for Scatter Motion, overrides Motion methods
 */
class ScatterMotion : public Motion {
public:
    bool chase(GameWorld &world, Player *ghost) override;
};
