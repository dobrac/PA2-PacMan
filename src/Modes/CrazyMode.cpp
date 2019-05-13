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

CrazyMode::CrazyMode(int length) : Mode(length) {

}

std::shared_ptr<Mode> CrazyMode::clone(int length) const {
    std::shared_ptr<CrazyMode> mode = std::make_shared<CrazyMode>(*this);
    mode->setLength(length);
    return mode;
}
