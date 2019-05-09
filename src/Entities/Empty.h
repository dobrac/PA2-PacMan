#pragma once

#include "Entity.h"

class Empty : public Entity {
public:
    explicit Empty(const Pos &pos);

    std::string print(const GameBoard &board) const override;

    EntityType getType() const override;

private:
};
