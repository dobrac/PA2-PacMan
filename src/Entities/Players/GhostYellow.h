#pragma once

#include "Ghost.h"

class GhostYellow : public Ghost {
public:
    GhostYellow(const Pos &pos, int speed = 250);

    bool chase(GameMap &map) override;

    std::string print() const override;
};
