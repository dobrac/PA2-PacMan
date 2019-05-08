#include "NormalMode.h"

#include "../Game/GameBoard.h"

bool NormalMode::update(GameBoard & board) {
    bool shouldUpdate = false;

    if (board.isStarted()) {
        // Move Ghosts
        for (auto &ghost : board.getGhosts()) {
            if (ghost->chase(board)) {
                shouldUpdate = true;
            }
        }
    }

    // Move PacMan
    int pac = board.getPacMan().move(board);
    if (pac == 2) {
        board.addPointsGot(1);
    }
    if (pac > 0) {
        shouldUpdate = true;
    }
    return shouldUpdate;
}

bool NormalMode::solveConflicts(GameBoard & board) {
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

std::string NormalMode::print() const {
    return "Normal";
}

Mode::ModeType NormalMode::getType() const {
    return MNormal;
}