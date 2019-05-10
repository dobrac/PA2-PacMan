#pragma once

#include "../Player.h"
#include "../PacMan.h"
#include <memory>

class GameWorld;

class Motion {
public:
    virtual bool chase(GameWorld &world, Player *ghost) = 0;

    static Pos findNextPos(const GameWorld &world, const Pos &from, const Pos &to);

private:
    struct TPosFind {
        TPosFind(const Pos &pos, std::shared_ptr<TPosFind> from) : m_Pos(pos), m_PosFrom(std::move(from)) {};
        Pos m_Pos;
        std::shared_ptr<TPosFind> m_PosFrom = nullptr;
    };
};
