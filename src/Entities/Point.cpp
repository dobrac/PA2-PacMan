#include "Point.h"

#include "../Game/GameBoard.h"
#include "Empty.h"

Point::Point(const Pos &pos) : Entity(pos) {
}

std::string Point::print(const GameBoard &) const {
    //return ".";
    return "·";
}

Entity::EntityType Point::getType() const {
    return EPoint;
}

void Point::remove(GameBoard &board) {
    board.addScreen(std::make_shared<Empty>(Empty(getPos())));
    board.addPointsGot(1);
    board.addScore(10);
    board.removeScreenAt(getPos());
}

