#pragma once

#include "Player.h"
#include "PacMan.h"

class GameWorld;
class Motion;

class Ghost : public Player {
public:
    Ghost(const Pos &pos, std::shared_ptr<Motion> &&motionBase);

    virtual bool chase(GameWorld &world) = 0;

    EntityType getType() const override;

protected:
    std::shared_ptr<Motion> m_MotionBase;
};
