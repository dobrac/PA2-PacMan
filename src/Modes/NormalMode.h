#pragma once

#include "Mode.h"

class NormalMode : public Mode {
public:
    bool update(GameBoard & board) override;
    ModeType getType() const override;
    std::string print() const override;
};
