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

    Pos posVecBack = getVec();
    if (!board.getArrowQueue().empty()) {
        setVec(board.getArrowQueue().get());

        if (setMovePos(board)) {
            board.getArrowQueue().pop();
            return true;
        }
    }

    setVec(posVecBack);
    if (!setMovePos(board) || posVecBack == Pos(0, 0)) {
        board.getArrowQueue().pop();
        return false;
    }
    return true;
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
    if (board.isFrightened()) {
        return "C";
    }

    return "O";
}

Entity::EntityType PacMan::getType() const {
    return EPacMan;
}

bool PacMan::setMovePos(GameBoard &board) {
    std::shared_ptr<Entity> ent = board.getScreenAt(getDirection());

    if (ent->getType() == EEmpty) {
        m_Position = getDirection();
        return true;
    }
    if (ent->getType() == EPoint || ent->getType() == EBonus) {
        board.removeScreenAt(getDirection());
        board.addScreen(std::make_shared<Empty>(Empty(getDirection())));
        m_Position = getDirection();
        if (ent->getType() == EBonus) {
            board.runInvincibleMode();
        } else if (ent->getType() == EPoint) {
            board.addPointsGot(1);
        }
        return true;
    }
    return false;
}

