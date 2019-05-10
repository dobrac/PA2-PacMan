#include "GameBoard.h"
#include "../Exceptions/ExceptionPosNotFound.h"
#include "../Entities/Players/GhostYellow.h"
#include "../Entities/Players/GhostRed.h"
#include "../Modes/InvincibleMode.h"
#include "../Entities/Cherry.h"
#include "../Random.h"

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

        spawnCherry();

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
        m_GameModeToChange = getSettings().getGameMode();
}

int GameBoard::getTimeChangeMode() const {
    if (m_GameMode->getType() == getSettings().getGameMode()->getType())
        return -1;

    int diff = TIME_INVINCIBLE_MODE - (int) m_TimerMode.elapsed();
    if (diff < 0)
        diff = -1;
    return diff;
}

bool GameBoard::isFrightened() const {
    return m_GameMode->getType() == Mode::MInvincible;
}

const Settings &GameBoard::getSettings() const {
    return m_Settings;
}

void GameBoard::setSettings(const Settings &settings) {
    m_Settings = settings;
    m_GameModeToChange = m_Settings.getGameMode();
    m_GameMode = m_GameModeToChange;
}

double GameBoard::getGameLength() const {
    return m_TimerGameLength.elapsed();
}

void GameBoard::spawnCherry() {
    if (((int) getGameLength()) % 60 != 0 || getGameLength() < 10)
        return;

    int ranX = Random::getInt(0, getX() - 1);
    int ranY = Random::getInt(0, getY() - 1);
    Pos ranPos(ranX, ranY);

    std::shared_ptr<Entity> entity = getScreenAt(ranPos);
    if (entity->getType() == Entity::EEmpty) {
        removeScreenAt(ranPos);
        addScreen(std::make_shared<Cherry>(Cherry(ranPos)));
    }
}
