#include "GameMode.h"
#include "../Modes/InvincibleMode.h"
#include "../Modes/ScatterMode.h"

const std::shared_ptr<Mode> &GameMode::getGameMode() const {
    return m_GameMode;
}

void GameMode::runScatterMode(int time) {
    if (isScatter())
        return;
    m_GameModeToChange = std::make_shared<ScatterMode>(ScatterMode(time));
}

void GameMode::runInvincibleMode() {
    if (isInvincible())
        return;
    m_GameModeToChange = std::make_shared<InvincibleMode>(InvincibleMode(getInvincibleModeLength()));
}

bool GameMode::isInvincible() const {
    return m_GameMode->getType() == Mode::MInvincible;
}

bool GameMode::isScatter() const {
    return m_GameMode->getType() == Mode::MScatter;
}

void GameMode::resetMode() {
    m_GameModeToChange = getDefaultMode();
}

int GameMode::getRemainingTimeMode() const {
    int diff = m_GameMode->getRemainingTime();
    if (diff <= 0)
        diff = -1;
    return diff;
}

bool GameMode::updateGameMode(GameBoard &board) {
    bool shouldUpdate = getGameMode()->update(board);

    m_GameMode = m_GameModeToChange;

    return shouldUpdate;
}
