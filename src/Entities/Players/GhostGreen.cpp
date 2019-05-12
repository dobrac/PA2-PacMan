#include "GhostGreen.h"

#include "Heuristics/RandomMotion.h"

#include "../../Game/GameBoard.h"
#include "Heuristics/AheadMotion.h"

GhostGreen::GhostGreen(const Pos &pos, int speed)
        : Ghost(pos,
                std::make_shared<AheadMotion>(AheadMotion()),
                std::make_shared<RandomMotion>(RandomMotion())) {
    setSpeed(speed);
}

std::string GhostGreen::print(const GameBoard &board) const {
    if (board.isInvincible()) {
        return "A";
    }
    return "G";
}

bool GhostGreen::chase(GameWorld &world) {
    if (checkTimerMove())
        return m_MotionBase->chase(world, this);
    else
        return false;
}

bool GhostGreen::frightened(GameWorld &world) {
    if (checkTimerMove(world.getPacMan().getSpeed() * 3))
        return m_MotionFrightened->chase(world, this);
    else
        return false;
}
