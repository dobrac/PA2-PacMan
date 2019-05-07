#pragma once

#include "Entity.h"

class Empty : public Entity {
public:
    Empty(const Pos &pos);

    std::string print() const override;

    EntityType getType() const override;

private:
};
