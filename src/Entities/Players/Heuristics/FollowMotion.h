#pragma once

#include "Motion.h"

class FollowMotion : public Motion {
public:
    bool chase(GameWorld &world, Player *ghost) override;

private:
    struct TPosFind {
        Pos m_Pos;
        std::shared_ptr<TPosFind> m_PosFrom = nullptr;
    };

    Pos findNextPos(const GameWorld &world, const Pos &from, const Pos &to);
};
