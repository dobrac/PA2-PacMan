#include "GhostYellow.h"

#include "Heuristics/RandomMotion.h"

GhostYellow::GhostYellow(const Pos &pos, int speed)
        : Ghost(pos,
                std::make_shared<RandomMotion>(RandomMotion()),
                std::make_shared<RandomMotion>(RandomMotion())) {
    setSpeed(speed);
}

std::string GhostYellow::print() const {
    return "Y";
}

bool GhostYellow::chase(GameWorld &world) {
    if (checkTimerMove())
        return m_MotionBase->chase(world, this);
    else
        return false;
}

bool GhostYellow::frightened(GameWorld &world) {
    if (checkTimerMove())
        return m_MotionFrightened->chase(world, this);
    else
        return false;
}
