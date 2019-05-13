#pragma once

#include "Player.h"
#include "PacMan.h"
#include "Heuristics/FollowMotion.h"
#include "Heuristics/ScatterMotion.h"

#include <memory>

class GameWorld;

class Motion;

/**
 * Abstract base class for Ghost, overrides method from Entity
 */
class Ghost : public Player {
public:
    /**
     * Construct new Ghost instance
     * @param pos Position to start
     * @param motionBase Base motion
     * @param motionFrightened Frightened motion
     */
    Ghost(const Pos &pos, std::shared_ptr<Motion> &&motionBase,
          std::shared_ptr<Motion> &&motionFrightened);

    /**
     * Chase methods for PacMan chasing
     * @param world reference to GameWorld to work with
     * @return true if position changed
     */
    virtual bool chase(GameWorld &world) = 0;

    /**
     * Frightened method for PacMan escaping
     * @param world reference to GameWorld to work with
     * @return true if position changed
     */
    virtual bool frightened(GameWorld &world) = 0;

    /**
     * Scatter method for Returning home
     * @param world reference to GameWorld to work with
     * @return true if position changed
     */
    bool scatter(GameWorld &world);

    /**
     * Follow method for PacMan chasing
     * @param world reference to GameWorld to work with
     * @return true if position changed
     */
    bool follow(GameWorld &world);

    /**
     * Get type of Entity
     * @return EntityType, EGhost
     */
    EntityType getType() const override;

protected:
    /**
     * Variable for storing base motion
     */
    std::shared_ptr<Motion> m_MotionBase;

    /**
     * Variable for storing frightened motion
     */
    std::shared_ptr<Motion> m_MotionFrightened;

    /**
     * Variable for storing follow motion
     */
    FollowMotion m_MotionFollow = FollowMotion();

    /**
     * Variable for storing scatter motion
     */
    ScatterMotion m_MotionScatter = ScatterMotion();
};
