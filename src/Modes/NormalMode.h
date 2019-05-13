#pragma once

#include "Mode.h"

/**
 * Normal Mode class, overrides methods from Mode
 */
class NormalMode : public Mode {
public:

    explicit NormalMode(int length);

    bool update(GameBoard &board) override;

    ModeType getType() const override;

    std::string print() const override;
};
