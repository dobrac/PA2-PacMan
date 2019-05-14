#include "Cherry.h"

#include "../Game/GameBoard.h"
#include "Empty.h"

Cherry::Cherry(const Pos &pos) : Entity(pos) {
}

std::string Cherry::print(const GameBoard &) const {
    return "@";
}

Entity::EntityType Cherry::getType() const {
    return ECherry;
}

void Cherry::remove(GameBoard &board) {
    board.addScreen(std::make_shared<Empty>(Empty(getPos())));
    board.addScore(100);
    board.getPacMan().addLives(1);
    board.removeScreenAt(getPos());
}

