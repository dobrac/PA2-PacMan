#pragma once

#include "GameMode.h"

/**
 * Class for handling game basics
 */
class GameBoard : public GameMode {
public:
    /**
     * Update method for updating and solving motions
     * @return true if something has changed
     */
    bool update();

    /**
     * Add max points that player can get
     * @param count points
     */
    void addPointsMax(int count);

    /**
     * Add got point that player have
     * @param count points
     */
    void addPointsGot(int count);


    /**
     * Get Max points
     * @return points
     */
    int getPointsMax() const;

    /**
     * Get points that player got
     * @return points
     */
    int getPoinsGot() const;

    /**
     * Check if the Game has ended
     * @return true if has ended
     */
    bool isEnded() const;

    /**
     * Check if the Game has started
     * @return true if has started
     */
    bool isStarted() const;

    /**
     * Check if the game has winner
     * @return true if so
     */
    bool checkWinner() const;

    /**
     * Check if the game has loser
     * @return true if so
     */
    bool checkLoser() const;

    /**
     * Run scatter mode
     */
    void runScatter();

    /**
     * Spawn Cherry in the plane
     */
    void spawnCherry();

    /**
     * Get Game length in seconds
     * @return Elapse Game length
     */
    double getGameLength() const;

private:
    /**
     * Maximum points to get
     */
    int m_PointsMax = 0;

    /**
     * Points already got
     */
    int m_PointsGot = 0;

    /**
     * Timer for Game length tracking
     */
    Timer<Timer_Type_Second, false> m_TimerGameLength;
};


