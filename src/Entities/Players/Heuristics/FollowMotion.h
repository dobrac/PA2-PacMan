#include <utility>

#pragma once

#include "Motion.h"

class FollowMotion : public Motion {
public:
    bool chase(GameWorld &world, Player *ghost) override;

private:
    struct TPosFind {
        TPosFind(const Pos & pos, std::shared_ptr<TPosFind>  from) :m_Pos(pos), m_PosFrom(std::move(from)) {};
        Pos m_Pos;
        std::shared_ptr<TPosFind> m_PosFrom = nullptr;
    };

    static Pos findNextPos(const GameWorld &world, const Pos &from, const Pos &to);
};
