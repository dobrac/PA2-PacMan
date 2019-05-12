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

    solveConflictsKill(board);

    // Move PacMan
    if (board.getPacMan().move(board)) {
        shouldUpdate = true;
    }

    solveConflictsKill(board);

    return shouldUpdate;
}

std::string InvincibleMode::print() const {
    return "Invincible";
}

Mode::ModeType InvincibleMode::getType() const {
    return MInvincible;
}

InvincibleMode::InvincibleMode(int length) : Mode(length) {

}
