#include "GhostRed.h"

#include "Heuristics/CompletelyRandomMotion.h"
#include "Heuristics/RandomMotion.h"

GhostRed::GhostRed(const Pos &pos, int speed)
        : Ghost(pos,
                std::make_shared<CompletelyRandomMotion>(CompletelyRandomMotion()),
                std::make_shared<RandomMotion>(RandomMotion())) {
    setSpeed(speed);
}

std::string GhostRed::print() const {
    return "R";
}

bool GhostRed::chase(GameWorld &world) {
    if (checkTimerMove())
        return m_MotionBase->chase(world, this);
    else
        return false;
}

bool GhostRed::frightened(GameWorld &world) {
    if (checkTimerMove())
        return m_MotionFrightened->chase(world, this);
    else
        return false;
}
