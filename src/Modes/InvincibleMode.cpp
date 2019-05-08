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
