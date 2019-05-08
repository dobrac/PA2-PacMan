#pragma once

#include "Entity.h"

class Bonus : public Entity {
public:
    Bonus(const Pos &pos);

    std::string print(const GameBoard &board) const override;

    EntityType getType() const override;

private:
};
