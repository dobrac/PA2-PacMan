#include "Mode.h"

#include "../Game/GameBoard.h"

Mode::Mode(int length) : m_Length(length) {

}

bool Mode::solveConflictsKill(GameBoard &board) {
    for (auto &ghost : board.getGhosts()) {
        if (ghost->getPos() == board.getPacMan().getPos()) {
            ghost->reset();
        }
    }
    return true;
}


bool Mode::solveConflictsDeath(GameBoard &board) {
    for (auto &ghost : board.getGhosts()) {
        if (ghost->getPos() == board.getPacMan().getPos()) {
            board.getArrowQueue().clear();
            board.getPacMan().removeLives(1);
            board.getPacMan().reset();
            for (auto &ghostRes : board.getGhosts()) {
                ghostRes->reset();
            }
            return true;
        }
    }
    return false;
}

bool Mode::shouldEnd() const {
    return getRemainingTime() <= 0;
}

int Mode::getRemainingTime() const {
    if (m_Length == 0)
        return -1;
    return (int) (m_Length - m_Timer.elapsed() + 1);
}
