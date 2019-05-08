#include "GhostBlue.h"
#include "Heuristics/FollowMotion.h"

GhostBlue::GhostBlue(const Pos &pos, int speed)
        : Ghost(pos,
                std::make_shared<FollowMotion>(FollowMotion())) {
    setSpeed(speed);
}

std::string GhostBlue::print() const {
    return "B";
}

bool GhostBlue::chase(GameWorld &world) {
    if (checkTimerMove())
        return m_MotionBase->chase(world, this);
    else
        return false;
}
