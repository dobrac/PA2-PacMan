#pragma once

#include "Ghost.h"

/**
 * Ghost Red class, overrides methods from Ghost
 */
class GhostRed : public Ghost {
public:
    /**
     * Constructs Ghost with speed
     * @param pos Position to start
     * @param speed Speed to start
     */
    explicit GhostRed(const Pos &pos, int speed = 250);

    bool chase(GameWorld &world) override;

    bool frightened(GameWorld &world) override;

    std::string print(const GameBoard &board) const override;
};
