#include "Bonus.h"

#include "../Game/GameBoard.h"
#include "Empty.h"

Bonus::Bonus(const Pos &pos) : Entity(pos) {
}

std::string Bonus::print(const GameBoard &) const {
    return "%";
}

Entity::EntityType Bonus::getType() const {
    return EBonus;
}

void Bonus::remove(GameBoard &board) {
    board.addScreen(std::make_shared<Empty>(Empty(getPos())));
    board.runInvincibleMode();
    board.removeScreenAt(getPos());
}

