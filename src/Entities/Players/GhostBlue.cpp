#include "GhostBlue.h"
#include "Heuristics/FollowMotion.h"
#include "Heuristics/RandomMotion.h"

GhostBlue::GhostBlue(const Pos &pos, int speed)
        : Ghost(pos,
                std::make_shared<FollowMotion>(FollowMotion()),
                std::make_shared<RandomMotion>(RandomMotion())) {
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

bool GhostBlue::frightened(GameWorld &world) {
    if (checkTimerMove())
        return m_MotionFrightened->chase(world, this);
    else
        return false;
}
