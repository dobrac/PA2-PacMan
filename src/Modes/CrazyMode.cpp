#include "CrazyMode.h"

#include "../Game/GameBoard.h"

bool CrazyMode::update(GameBoard & board) {
    bool shouldUpdate = false;

    if (board.isStarted()) {
        // Move Ghosts
        for (auto &ghost : board.getGhosts()) {
            if (ghost->follow(board)) {
                shouldUpdate = true;
            }
        }
    }

    solveConflictsDeath(board);

    // Move PacMan
    if (board.getPacMan().move(board)) {
        shouldUpdate = true;
    }

    solveConflictsDeath(board);

    return shouldUpdate;
}

std::string CrazyMode::print() const {
    return "Crazy";
}

Mode::ModeType CrazyMode::getType() const {
    return MCrazy;
}
