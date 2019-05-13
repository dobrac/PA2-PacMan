#pragma once

#include "Entity.h"

/**
 * Class for Border entity handling, overrides methods from Entity
 */
class Border : public Entity {
public:
    explicit Border(const Pos &pos);

    std::string print(const GameBoard &board) const override;

    EntityType getType() const override;
};
