#pragma once

#include "Ghost.h"

/**
 * Ghost Yellow class, overrides methods from Ghost
 */
class GhostYellow : public Ghost {
public:
    /**
     * Constructs Ghost with speed
     * @param pos Position to start
     * @param speed Speed to start
     */
    explicit GhostYellow(const Pos &pos, int speed = 250);

    bool chase(GameWorld &world) override;

    bool frightened(GameWorld &world) override;

    std::string print(const GameBoard &board) const override;
};
