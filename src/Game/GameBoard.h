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

    /**
     * Add players score
     * @param count points
     */
    void addScore(int points);

    /**
     * Get players score
     * @return score
     */
    int getScore() const;

    /**
     * Increments level
     */
    void incrementLevel();

    /**
     * Get game level
     * @return actual game level
     */
    int getLevel() const;

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
     * Score gained
     */
    int m_Score = 0;

    /**
     * Game level
     */
    int m_Level = 1;

    /**
     * Timer for Game length tracking
     */
    Timer<Timer_Type_Second, false> m_TimerGameLength;

    /**
     * Static constant for MINIMUM TIME between Cherry spawn
     */
    static const int TIME_MIN_CHERRY_SPAWN = 10;

    /**
     * Timer for tracking if you can spawn next Cherry
     */
    Timer<Timer_Type_Second> m_TimerNextCherry;
};


