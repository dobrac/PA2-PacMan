#pragma once

#include "Motion.h"

class CompletelyRandomMotion : public Motion {
public:
    bool chase(GameMap &map, Player * ghost) override;
};
