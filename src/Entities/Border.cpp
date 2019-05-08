#include "Border.h"

Border::Border(const Pos &pos) : Entity(pos) {
}

std::string Border::print(const GameBoard &) const {
    return "*";
}

Entity::EntityType Border::getType() const {
    return EBorder;
}

