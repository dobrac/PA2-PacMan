#pragma once

#include "Entity.h"

/**
 * Class for Cherry entity handling, overrides methods from Entity
 */
class Cherry : public Entity {
public:
    explicit Cherry(const Pos &pos);

    std::string print(const GameBoard &board) const override;

    void remove(GameBoard &board) override;

    EntityType getType() const override;
};
