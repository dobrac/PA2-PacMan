#pragma once

#include "Ghost.h"

class GhostRed : public Ghost {
public:
    GhostRed(const Pos &pos, int speed = 250);

    bool chase(GameMap &map) override;

    std::string print() const override;
};
