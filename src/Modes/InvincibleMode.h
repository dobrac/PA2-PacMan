#pragma once

#include "Mode.h"

class InvincibleMode : public Mode {
public:
    bool update(GameBoard & board) override;
    bool solveConflicts(GameBoard & board) override;
    ModeType getType() const override;
    std::string print() const override;
};
