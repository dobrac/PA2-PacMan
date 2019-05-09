#pragma once

#include "Entity.h"

class Border : public Entity {
public:
    explicit Border(const Pos & pos);

    std::string print(const GameBoard &board) const override;

    EntityType getType() const override;

private:
};
