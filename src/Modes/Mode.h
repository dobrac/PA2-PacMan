#pragma once

#include <string>
#include <memory>
#include "../Timer.h"

class GameBoard;

/**
 * Abstract base class for Modes
 */
class Mode {
public:
    /**
     * Enum with Mode types
     */
    enum ModeType {
        MNormal,
        MInvincible,
        MCrazy,
        MScatter
    };

    /**
     * Instance new Mode
     * @param length Mode length, 0 for infinity
     */
    explicit Mode(int length);

    /**
     * Do all necessary steps to move entities on the plane
     * @param board GameBoard reference to work with
     * @return true if plane has changed and should redraw
     */
    virtual bool update(GameBoard &board) = 0;

    /**
     * Get type of Mode from enum
     * @return ModeType from enum
     */
    virtual ModeType getType() const = 0;

    /**
     * Print Mode name
     * @return string with Mode name
     */
    virtual std::string print() const = 0;

    /**
     * Method for solving entities collisions, PacMan can kill ghosts
     * @param board GameBoard reference to work with
     * @return true
     */
    virtual bool solveConflictsKill(GameBoard &board);

    /**
     * Method for solving entities collisions, Ghost can kill PacMan
     * @param board GameBoard reference to work with
     * @return true if PacMan died
     */
    virtual bool solveConflictsDeath(GameBoard &board);

    /**
     * Method for checking if time for this mode has passed
     * @return true if the mode should end
     */
    bool shouldEnd() const;

    /**
     * Get remaining mode time
     * @return remaining mode time
     */
    int getRemainingTime() const;

private:
    /**
     * Variable for storing Mode length
     */
    int m_Length;

    /**
     * Timer for tracking Mode elapsed time in seconds
     */
    Timer<Timer_Type_Second> m_Timer;
};
