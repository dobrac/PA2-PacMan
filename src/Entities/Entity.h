#pragma once

#include "../Pos.h"

#include <string>
#include <list>

class GameBoard;

/**
 * Entity base abstract class
 */
class Entity {
public:
    /**
     * Enum with entities types
     */
    enum EntityType {
        EPacMan,
        EBorder,
        EPoint,
        EEmpty,
        EGhost,
        EBonus,
        ECherry
    };

    /**
     * Construct new Entity at Pos
     * @param pos Pos with coordinates on the plane
     */
    explicit Entity(const Pos &pos);

    /**
     * Print entity symbol
     * @param board GameBoard reference to work with
     * @return string with Entity symbol
     */
    virtual std::string print(const GameBoard &board) const = 0;

    /**
     * Handle removing Entity from plane
     * @param board GameBoard reference to work with
     */
    virtual void remove(GameBoard &board);

    /**
     * Get Entity Type
     * @return EntityType from enum
     */
    virtual EntityType getType() const = 0;

    /**
     * Get Entity Pos on the plane
     * @return Entity position
     */
    const Pos &getPos() const;

    /**
     * Set Entity position
     * @param pos New entity position
     */
    void setPos(const Pos &pos);

    /**
     * Compare two Entities
     * @param ent other Entity to compare
     * @return true if Entity to compare position is greater
     */
    bool operator<(const Entity &ent);

private:

    /**
     * Position value for storing possition
     */
    Pos m_Position;
};
