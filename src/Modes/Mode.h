#pragma once

#include <string>

class GameBoard;

class Mode {
public:
    enum ModeType {
        MNormal,
        MInvincible,
        MCrazy,
        MScatter
    };

    virtual bool update(GameBoard &board) = 0;

    virtual ModeType getType() const = 0;

    virtual std::string print() const = 0;

    virtual bool solveConflictsKill(GameBoard &board);

    virtual bool solveConflictsDeath(GameBoard &board);
};
