#pragma once

#include "Player.h"

class GameBoard;

class PacMan : public Player {
public:
    PacMan(const Pos &pos, int speed = 250);

    /**
     *
     * @param board Bord to play on
     * @return 0 when pacman is not moving, 1 when pacman has moved, 2 when pacman has moved and got point
     */
    int move(GameBoard &board);

    std::string print() const override;

    EntityType getType() const override;

private:

    int setMovePos(GameBoard &board);
};
