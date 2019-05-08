#pragma once

#include "Player.h"
#include "PacMan.h"

#include <memory>

class GameWorld;
class Motion;

class Ghost : public Player {
public:
    Ghost(const Pos &pos, std::shared_ptr<Motion> &&motionBase, std::shared_ptr<Motion> &&motionFrightened);

    virtual bool chase(GameWorld &world) = 0;
    virtual bool frightened(GameWorld &world) = 0;

    EntityType getType() const override;

protected:
    std::shared_ptr<Motion> m_MotionBase;
    std::shared_ptr<Motion> m_MotionFrightened;
};
