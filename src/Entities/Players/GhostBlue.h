#pragma once

#include "Ghost.h"

class GhostBlue : public Ghost {
public:
    GhostBlue(const Pos &pos, int speed = 250);

    bool chase(GameWorld &world) override;

    std::string print() const override;
};
