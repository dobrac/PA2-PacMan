#include "InvincibleMode.h"

#include "../Game/GameBoard.h"

bool InvincibleMode::update(GameBoard & board) {
    bool shouldUpdate = false;

    if (board.isStarted()) {
        // Move Ghosts
        for (auto &ghost : board.getGhosts()) {
            if (ghost->frightened(board)) {
                shouldUpdate = true;
            }
        }
    }

    solveConflicts(board);

    // Move PacMan
    if (board.getPacMan().move(board)) {
        shouldUpdate = true;
    }

    solveConflicts(board);

    return shouldUpdate;
}

bool InvincibleMode::solveConflicts(GameBoard & board) {
    for (auto &ghost : board.getGhosts()) {
        if (ghost->getPos() == board.getPacMan().getPos()) {
            ghost->setVec({0,0});
            ghost->resetPos();
        }
    }
    return false;
}

std::string InvincibleMode::print() const {
    return "Invincible";
}

Mode::ModeType InvincibleMode::getType() const {
    return MInvincible;
}
