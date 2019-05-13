#pragma once

#include "../Player.h"
#include "../PacMan.h"
#include <memory>

class GameWorld;

/**
 * Abstract class for Motion handling
 */
class Motion {
public:
    /**
     * Chase method, does some algorithm for movement
     * @param world reference to GameWorld to work with
     * @param ghost reference to Ghost to work with
     * @return
     */
    virtual bool chase(GameWorld &world, Player *ghost) = 0;

    /**
     * Algorithm for finding path in the plane
     * @param world reference to GameWorld to work with
     * @param from Position from
     * @param to Position to
     * @return Next Position to move to
     */
    static Pos findNextPos(const GameWorld &world, const Pos &from, const Pos &to);

private:
    /**
     * Struct for tracking path in finding end position
     */
    struct TPosFind {
        TPosFind(const Pos &pos, std::shared_ptr<TPosFind> from) : m_Pos(pos), m_PosFrom(std::move(from)) {};
        Pos m_Pos;
        std::shared_ptr<TPosFind> m_PosFrom = nullptr;
    };
};
