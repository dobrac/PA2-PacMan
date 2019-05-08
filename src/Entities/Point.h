#pragma once

#include "Entity.h"

class Point : public Entity {
public:
    Point(const Pos &pos);

    std::string print(const GameBoard &board) const override;

    EntityType getType() const override;

private:
};
