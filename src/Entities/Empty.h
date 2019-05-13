#pragma once

#include "Entity.h"

/**
 * Class for Empty entity handling, overrides methods from Entity
 */
class Empty : public Entity {
public:
    explicit Empty(const Pos &pos);

    std::string print(const GameBoard &board) const override;

    EntityType getType() const override;
};
