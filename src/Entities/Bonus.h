#pragma once

#include "Entity.h"

/**
 * Class for Bonus entity handling, overrides methods from Entity
 */
class Bonus : public Entity {
public:
    explicit Bonus(const Pos &pos);

    std::string print(const GameBoard &board) const override;

    void remove(GameBoard &board) override;

    EntityType getType() const override;
};
