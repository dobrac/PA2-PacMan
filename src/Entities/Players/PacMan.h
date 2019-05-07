#pragma once

#include "Player.h"
#include "../../Game/GameMap.h"

class PacMan : public Player {
public:
    PacMan(const Pos &pos, int speed = 250);

    /**
     *
     * @param map Map to move on
     * @return 0 when pacman is not moving, 1 when pacman has moved, 2 when pacman has moved and got point
     */
    int move(GameMap &map);

    std::string print() const override;

    EntityType getType() const override;

private:

    int setMovePos(GameMap &map);
};
