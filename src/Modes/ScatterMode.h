#pragma once

#include "Mode.h"

/**
 * Scatter Mode class, overrides methods from Mode
 */
class ScatterMode : public Mode {
public:
    explicit ScatterMode(int length);

    bool update(GameBoard &board) override;

    ModeType getType() const override;

    std::string print() const override;

    std::shared_ptr<Mode> clone(int length) const override;
};
