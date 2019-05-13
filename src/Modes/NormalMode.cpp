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

    solveConflictsDeath(board);

    // Move PacMan
    if (board.getPacMan().move(board)) {
        shouldUpdate = true;
    }

    solveConflictsDeath(board);

    return shouldUpdate;
}

std::string NormalMode::print() const {
    return "Normal";
}

Mode::ModeType NormalMode::getType() const {
    return MNormal;
}

NormalMode::NormalMode(int length) : Mode(length) {

}

std::shared_ptr<Mode> NormalMode::clone(int length) const {
    std::shared_ptr<NormalMode> mode = std::make_shared<NormalMode>(*this);
    mode->setLength(length);
    return mode;
}