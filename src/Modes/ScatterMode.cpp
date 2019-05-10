#include "ScatterMode.h"

#include "../Game/GameBoard.h"

bool ScatterMode::update(GameBoard &board) {
    bool shouldUpdate = false;

    if (board.isStarted()) {
        // Move Ghosts
        for (auto &ghost : board.getGhosts()) {
            if (ghost->scatter(board)) {
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

std::string ScatterMode::print() const {
    return "Scatter";
}

Mode::ModeType ScatterMode::getType() const {
    return MScatter;
}
