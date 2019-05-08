#include "GhostRed.h"

#include "Heuristics/CompletelyRandomMotion.h"

GhostRed::GhostRed(const Pos &pos, int speed)
        : Ghost(pos,
                std::make_shared<CompletelyRandomMotion>(CompletelyRandomMotion())) {
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
