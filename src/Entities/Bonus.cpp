#include "Bonus.h"

Bonus::Bonus(const Pos &pos) : Entity(pos) {
}

std::string Bonus::print(const GameBoard &) const {
    return "%";
}

Entity::EntityType Bonus::getType() const {
    return EBonus;
}

