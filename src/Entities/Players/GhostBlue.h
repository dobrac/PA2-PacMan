#pragma once

#include "Ghost.h"

/**
 * Ghost Blue class, overrides methods from Ghost
 */
class GhostBlue : public Ghost {
public:
    /**
     * Constructs Ghost with speed
     * @param pos Position to start
     * @param speed Speed to start
     */
    explicit GhostBlue(const Pos &pos, int speed = 250);

    bool chase(GameWorld &world) override;

    bool frightened(GameWorld &world) override;

    std::string print(const GameBoard &board) const override;
};
