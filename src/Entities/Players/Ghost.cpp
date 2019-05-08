#include "Ghost.h"

Ghost::Ghost(const Pos &pos,
             std::shared_ptr<Motion> &&motionBase,
             std::shared_ptr<Motion> &&motionFrightened)
        : Player(pos),
          m_MotionBase(motionBase),
          m_MotionFrightened(motionFrightened){
}

Entity::EntityType Ghost::getType() const {
    return EGhost;
}