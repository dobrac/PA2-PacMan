#pragma once

#include "../Pos.h"

#include <string>
#include <list>

class GameBoard;

class Entity {
public:
    enum EntityType {
        EPacMan,
        EBorder,
        EPoint,
        EEmpty,
        EGhost,
        EBonus
    };

    Entity(const Pos &pos);

    virtual std::string print(const GameBoard &board) const = 0;

    virtual EntityType getType() const = 0;

    bool intersects(const Entity &ent) const;

    const Pos &getPos() const;

    void setPos(const Pos &pos);

protected:

    Pos m_Position;
};
