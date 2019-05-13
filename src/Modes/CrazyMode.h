#pragma once

#include "Mode.h"

/**
 * Crazy Mode class, overrides methods from Mode
 */
class CrazyMode : public Mode {
public:
    explicit CrazyMode(int length);

    bool update(GameBoard &board) override;

    ModeType getType() const override;

    std::string print() const override;

    std::shared_ptr<Mode> clone(int length) const override;
};
