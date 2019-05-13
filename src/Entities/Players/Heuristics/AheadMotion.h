#include <utility>

#pragma once

#include "Motion.h"

/**
 * Class for Ahead Motion, overrides Motion methods
 */
class AheadMotion : public Motion {
public:
    bool chase(GameWorld &world, Player *ghost) override;
};
