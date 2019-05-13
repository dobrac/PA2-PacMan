#pragma once

#include "../Entity.h"
#include "../../Pos.h"
#include "../../Timer.h"

/**
 * Class for Players handling, inheritance of Entity
 */
class Player : public Entity {
public:

    /**
     * Construct Player
     * @param pos Position on plane
     */
    explicit Player(const Pos &pos);

    /**
     * Set Vector for moving direction
     * @param vec Vector with direction
     */
    void setVec(const Pos &vec);

    /**
     * Get direction vector
     * @return const reference to vector
     */
    const Pos &getVec() const;

    /**
     * Get default/start Pos on plane
     * @return
     */
    const Pos &getDefaultPos() const;

    /**
     * Get direction
     * @return Position + Vector
     */
    Pos getDirection() const;

    /**
     * Get timer for movement speeds
     * @return reference to timer
     */
    Timer<Timer_Type_Millisecond> &getTimer();

    /**
     * Set Players speed
     * @param speed Speed value in milliseconds (how often should Player update)
     * @return true if speed was successfully set
     */
    bool setSpeed(int speed);

    /**
     * Get speed of Player
     * @return Speed value in milliseconds
     */
    int getSpeed() const;

    /**
     * Reset Player position to default position
     */
    void resetPos();

    /**
     * Check whether Player should move on the plane
     * @param speed Optional different speed, useful for specific modes
     * @return
     */
    bool checkTimerMove(int speed = 0);

    /**
     * Reset Player position and Vec to {0,0}
     */
    void reset();

protected:
    /**
     * Vector for storing direction
     */
    Pos m_Vec = Pos(0, 0);

    /**
     * Default position of player
     */
    Pos m_DefaultPos;

    /**
     * Timer for speed (updates) handling
     */
    Timer<Timer_Type_Millisecond> m_Timer;

    /**
     * Speed value in milliseconds
     */
    int m_Speed = 0;
};
