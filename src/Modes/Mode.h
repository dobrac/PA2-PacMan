#pragma once

#include <string>

class GameBoard;

class Mode {
public:
    enum ModeType {
        MNormal,
        MInvincible
    };

    virtual bool update(GameBoard & board) = 0;
    virtual bool solveConflicts(GameBoard & board) = 0;
    virtual ModeType getType() const = 0;
    virtual std::string print() const = 0;
};
