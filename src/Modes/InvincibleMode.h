#pragma once

#include "Mode.h"

/**
 * Invincible Mode class, overrides methods from Mode
 */
class InvincibleMode : public Mode {
public:
    explicit InvincibleMode(int length);

    bool update(GameBoard &board) override;

    ModeType getType() const override;

    std::string print() const override;
};
