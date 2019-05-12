#pragma once

#include <string>
#include <memory>
#include "../Timer.h"

class GameBoard;

class Mode {
public:
    enum ModeType {
        MNormal,
        MInvincible,
        MCrazy,
        MScatter
    };

    Mode(int length);

    virtual bool update(GameBoard &board) = 0;

    virtual ModeType getType() const = 0;

    virtual std::string print() const = 0;

    virtual bool solveConflictsKill(GameBoard &board);

    virtual bool solveConflictsDeath(GameBoard &board);

    const Timer<Timer_Type_Second> & getTimer() const;

    bool shouldEnd() const;
    int getRemainingTime() const;
private:
    int m_Length;
    Timer<Timer_Type_Second> m_Timer;
};
