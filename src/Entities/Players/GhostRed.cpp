#include "GhostRed.h"

#include "Heuristics/RandomMotion.h"

#include "../../Game/GameBoard.h"

GhostRed::GhostRed(const Pos &pos, int speed)
        : Ghost(pos,
                std::make_shared<RandomMotion>(RandomMotion()),
                std::make_shared<RandomMotion>(RandomMotion())) {
    setSpeed(speed);
}

std::string GhostRed::print(const GameBoard &board) const {
    if (board.isInvincible()) {
        return "A";
    }
    return "R";
}

bool GhostRed::chase(GameWorld &world) {
    if (checkTimerMove())
        return m_MotionBase->chase(world, this);
    else
        return false;
}

bool GhostRed::frightened(GameWorld &world) {
    if (checkTimerMove(world.getPacMan().getSpeed() * 3))
        return m_MotionFrightened->chase(world, this);
    else
        return false;
}
