#pragma once

#include "Player.h"
#include "../../Game/GameMap.h"
#include "Heuristics/Motion.h"

class Ghost : public Player {
public:
    Ghost(const Pos &pos, std::shared_ptr<Motion> &&motionBase);

    virtual bool chase(GameMap &map) = 0;

    EntityType getType() const override;

protected:
    std::shared_ptr<Motion> m_MotionBase;
};
