#pragma once

#include "Entity.h"

class Border : public Entity {
public:
    Border(const Pos & pos);

    std::string print() const override;

    EntityType getType() const override;

private:
};
