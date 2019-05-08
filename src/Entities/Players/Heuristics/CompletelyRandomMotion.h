#pragma once

#include "Motion.h"

class CompletelyRandomMotion : public Motion {
public:
    bool chase(GameWorld &world, Player * ghost) override;
};
