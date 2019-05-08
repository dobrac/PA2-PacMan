#include "Empty.h"

Empty::Empty(const Pos &pos) : Entity(pos) {
}

std::string Empty::print(const GameBoard &) const {
    return " ";
}

Entity::EntityType Empty::getType() const {
    return EEmpty;
}

