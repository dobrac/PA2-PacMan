#pragma once

#include "Entity.h"

/**
 * Class for Point entity handling, overrides methods from Entity
 */
class Point : public Entity {
public:
    explicit Point(const Pos &pos);

    std::string print(const GameBoard &board) const override;

    void remove(GameBoard &board) override;

    EntityType getType() const override;
};
