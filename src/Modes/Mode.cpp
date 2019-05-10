#include "Mode.h"

#include "../Game/GameBoard.h"

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