#include "GhostYellow.h"

#include "Heuristics/RandomMotion.h"

#include "../../Game/GameBoard.h"

GhostYellow::GhostYellow(const Pos &pos, int speed)
        : Ghost(pos,
                std::make_shared<RandomMotion>(RandomMotion()),
                std::make_shared<RandomMotion>(RandomMotion())) {
    setSpeed(speed);
}

std::string GhostYellow::print(const GameBoard &board) const {
    if (board.isFrightened()) {
        return "A";
    }
    return "Y";
}

bool GhostYellow::chase(GameWorld &world) {
    if (checkTimerMove())
        return m_MotionBase->chase(world, this);
    else
        return false;
}

bool GhostYellow::frightened(GameWorld &world) {
    if (checkTimerMove(world.getPacMan().getSpeed()*2))
        return m_MotionFrightened->chase(world, this);
    else
        return false;
}
