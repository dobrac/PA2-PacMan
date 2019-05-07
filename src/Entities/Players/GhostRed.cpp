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

bool GhostRed::chase(GameMap &map) {
    return m_MotionBase->chase(map, this);
}
