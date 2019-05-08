#pragma once

#include "../Pos.h"

#include <string>
#include <list>

class Entity {
public:
    enum EntityType {
        EPacMan,
        EBorder,
        EPoint,
        EEmpty,
        EGhost
    };

    Entity(const Pos &pos);

    virtual std::string print() const = 0;

    virtual EntityType getType() const = 0;

    bool intersects(const Entity &ent) const;

    const Pos &getPos() const;

    void setPos(const Pos &pos);

protected:

    Pos m_Position;
};
