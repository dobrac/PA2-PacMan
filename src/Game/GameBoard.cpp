#include "GameBoard.h"
#include "../Exceptions/ExceptionPosNotFound.h"
#include "../Entities/Players/GhostYellow.h"
#include "../Entities/Players/GhostRed.h"
#include "../Modes/InvincibleMode.h"

void GameBoard::addPointsMax(int count) {
    m_PointsMax += count;
}

void GameBoard::addPointsGot(int count) {
    m_PointsGot += count;
}

int GameBoard::getPointsMax() const {
    return m_PointsMax;
}

int GameBoard::getPoinsGot() const {
    return m_PointsGot;
}

bool GameBoard::isStarted() const {
    return getPacMan().getVec() != Pos(0, 0) && !isEnded();
}

bool GameBoard::isEnded() const {
    return checkWinner() || checkLoser();
}

bool GameBoard::checkWinner() const {
    return getPoinsGot() == getPointsMax();
}

bool GameBoard::checkLoser() const {
    return m_Lives == 0;
}

int GameBoard::getLives() const {
    return m_Lives;
}

const std::shared_ptr<Mode> &GameBoard::getGameMode() const {
    return m_GameMode;
}

bool GameBoard::update() {
    if (!isEnded()) {
        if (m_TimerMode.elapsed() > 10) {
            resetMode();
        }

        bool shouldUpdate = m_GameMode->update(*this);
        m_GameMode = m_GameModeToChange;
        return shouldUpdate;
    } else {
        return false;
    }
}

void GameBoard::removeLives(int count) {
    if (count > m_Lives)
        count = m_Lives;
    m_Lives -= count;
}

void GameBoard::runInvincibleMode() {
    m_GameModeToChange = std::make_shared<InvincibleMode>(InvincibleMode());
    m_TimerMode.reset();
}

void GameBoard::resetMode() {
    if (m_TimerMode.elapsed() >= TIME_INVINCIBLE_MODE && m_GameMode->getType() == Mode::MInvincible)
        m_GameModeToChange = m_GameModeDefault;
}

int GameBoard::getTimeChangeMode() const {
    int diff = TIME_INVINCIBLE_MODE - (int) m_TimerMode.elapsed();
    if (diff < 0)
        diff = -1;
    return diff;
}

bool GameBoard::isFrightened() const {
    return m_GameMode->getType() == Mode::MInvincible;
}
