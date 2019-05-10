#include "Ghost.h"

#include "../../Game/GameWorld.h"

Ghost::Ghost(const Pos &pos,
             std::shared_ptr<Motion> &&motionBase,
             std::shared_ptr<Motion> &&motionFrightened)
        : Player(pos),
          m_MotionBase(motionBase),
          m_MotionFrightened(motionFrightened) {
}

Entity::EntityType Ghost::getType() const {
    return EGhost;
}

bool Ghost::follow(GameWorld &world) {
    if (checkTimerMove(world.getPacMan().getSpeed()))
        return m_MotionFollow.chase(world, this);
    else
        return false;
}

bool Ghost::scatter(GameWorld &world) {
    if (checkTimerMove())
        return m_MotionScatter.chase(world, this);
    else
        return false;
}
