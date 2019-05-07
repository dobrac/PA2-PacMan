#include "GhostYellow.h"

#include "Heuristics/RandomMotion.h"

GhostYellow::GhostYellow(const Pos &pos, int speed)
        : Ghost(pos,
                std::make_shared<RandomMotion>(RandomMotion())) {
    setSpeed(speed);
}

std::string GhostYellow::print() const {
    return "Y";
}

bool GhostYellow::chase(GameMap &map) {
    return m_MotionBase->chase(map, this);
}
