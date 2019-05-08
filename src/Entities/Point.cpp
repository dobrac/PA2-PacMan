#include "Point.h"

Point::Point(const Pos &pos) : Entity(pos) {
}

std::string Point::print(const GameBoard &) const {
    return ".";
}

Entity::EntityType Point::getType() const {
    return EPoint;
}

