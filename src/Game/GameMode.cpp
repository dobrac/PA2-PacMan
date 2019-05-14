#include "GameMode.h"
#include "../Modes/InvincibleMode.h"
#include "../Modes/ScatterMode.h"

const std::shared_ptr<Mode> &GameMode::getGameMode() const {
    return m_GameMode;
}

void GameMode::runInvincibleMode() {
    if (!isInvincible()) {
        m_GameMode->getTimer().pause();
        m_ModeQueue.addFront(m_GameMode);
    }
    m_GameModeToChange = std::make_shared<InvincibleMode>(InvincibleMode(getInvincibleModeLength() - 1));
}

bool GameMode::isInvincible() const {
    return m_GameMode->getType() == Mode::MInvincible;
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

void GameMode::nextMode() {
    if (m_ModeQueue.empty())
        return;

    m_GameModeToChange = m_ModeQueue.get();
    m_GameModeToChange->getTimer().resume();

    m_ModeQueue.pop();
}

void GameMode::setupModes() {
    m_ModeQueue.clear();

    m_ModeQueue.add(std::make_shared<ScatterMode>(ScatterMode(getScatterModeLength())));
    m_ModeQueue.add(getDefaultMode()->clone(20));
    m_ModeQueue.add(std::make_shared<ScatterMode>(ScatterMode(getScatterModeLength())));
    m_ModeQueue.add(getDefaultMode()->clone(20));
    m_ModeQueue.add(std::make_shared<ScatterMode>(ScatterMode(getScatterModeLength())));
    m_ModeQueue.add(getDefaultMode()->clone(20));
    m_ModeQueue.add(std::make_shared<ScatterMode>(ScatterMode(getScatterModeLength())));
    m_ModeQueue.add(getDefaultMode());
}
