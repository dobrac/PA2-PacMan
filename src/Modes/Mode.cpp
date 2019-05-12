#include "Mode.h"

#include "../Game/GameBoard.h"

Mode::Mode(int length) : m_Length(length) {

}

bool Mode::solveConflictsKill(GameBoard &board) {
    for (auto &ghost : board.getGhosts()) {
        if (ghost->getPos() == board.getPacMan().getPos()) {
            ghost->setVec({0, 0});
            ghost->resetPos();
        }
    }
    return false;
}


bool Mode::solveConflictsDeath(GameBoard &board) {
    for (auto &ghost : board.getGhosts()) {
        if (ghost->getPos() == board.getPacMan().getPos()) {
            board.removeLives(1);
            board.getPacMan().setVec({0, 0});
            board.getPacMan().resetPos();
            for (auto &ghostRes : board.getGhosts()) {
                ghostRes->resetPos();
            }
            return true;
        }
    }
    return false;
}

const Timer<Timer_Type_Second> &Mode::getTimer() const {
    return m_Timer;
}

bool Mode::shouldEnd() const {
    return getRemainingTime() <= 0;
}

int Mode::getRemainingTime() const {
    if (m_Length == 0)
        return -1;
    return m_Length - m_Timer.elapsed() + 1;
}
