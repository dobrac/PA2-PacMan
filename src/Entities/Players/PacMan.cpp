#include "PacMan.h"
#include "../Empty.h"
#include "../../Game/GameBoard.h"

#include <memory>

PacMan::PacMan(const Pos &pos, int speed) : Player(pos) {
    setSpeed(speed);
}

int PacMan::move(GameBoard &board) {
    if (!checkTimerMove()) {
        return 0;
    }

    int toReturn;

    Pos posVecBack = getVec();
    if (!board.getArrowQueue().empty()) {
        setVec(board.getArrowQueue().get());

        toReturn = setMovePos(board);
        if (toReturn > 0) {
            board.getArrowQueue().pop();
            return toReturn;
        }
    }

    setVec(posVecBack);
    toReturn = setMovePos(board);
    if (toReturn == 0 || posVecBack == Pos(0, 0)) {
        board.getArrowQueue().pop();
        return toReturn;
    }
    return toReturn;
}

std::string PacMan::print(const GameBoard &board) const {
    /*if (m_Vec == Pos(1, 0))
        return "→";
    else if (m_Vec == Pos(-1, 0))
        return "←";
    else if (m_Vec == Pos(0, 1))
        return "↓";
    else if (m_Vec == Pos(0, -1))
        return "↑";
    else*/
    if (board.getGameMode()->getType() == Mode::MNormal) {
        return "O";
    } else {
        return "C";
    }
}

Entity::EntityType PacMan::getType() const {
    return EPacMan;
}

int PacMan::setMovePos(GameBoard &board) {
    std::shared_ptr<Entity> ent = board.getScreenAt(getDirection());

    if (ent->getType() == EEmpty) {
        m_Position = getDirection();
        return 1;
    }
    if (ent->getType() == EPoint || ent->getType() == EBonus) {
        board.removeScreenAt(getDirection());
        board.addScreen(std::make_shared<Empty>(Empty(getDirection())));
        m_Position = getDirection();
        if (ent->getType() == EBonus) {
            board.runInvincibleMode();
        }
        return 2;
    }
    return 0;
}

