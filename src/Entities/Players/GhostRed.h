#pragma once

#include "Ghost.h"

class GhostRed : public Ghost {
public:
    GhostRed(const Pos &pos, int speed = 250);

    bool chase(GameWorld &world) override;
    bool frightened(GameWorld &world) override;

    std::string print(const GameBoard &board) const override;
};
