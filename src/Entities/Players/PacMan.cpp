#include "PacMan.h"
#include "../Empty.h"
#include "../../Game/GameBoard.h"

#include <memory>

PacMan::PacMan(const Pos &pos, int speed) : Player(pos) {
    setSpeed(speed);
}

bool PacMan::move(GameBoard &board) {
    if (!checkTimerMove()) {
        return false;
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
    if (board.isInvincible()) {
        return "C";
    }

    return "O";
}

Entity::EntityType PacMan::getType() const {
    return EPacMan;
}

bool PacMan::setMovePos(GameBoard &board) {
    std::shared_ptr<Entity> ent = board.getScreenAt(getDirection());
    if (ent->getType() == EBorder)
        return false;

    ent->remove(board);

    setPos(getDirection());
    return true;
}

int PacMan::getLives() const {
    return m_Lives;
}

void PacMan::removeLives(int count) {
    if (count < 0)
        return;

    if (count > m_Lives)
        count = m_Lives;
    m_Lives -= count;
}

void PacMan::addLives(int count) {
    if (count < 0)
        return;

    m_Lives += count;
}
