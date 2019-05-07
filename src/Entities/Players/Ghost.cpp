#include "Ghost.h"

Ghost::Ghost(const Pos &pos,
             std::shared_ptr<Motion> &&motionBase)
        : Player(pos),
          m_MotionBase(motionBase) {
}

Entity::EntityType Ghost::getType() const {
    return EGhost;
}