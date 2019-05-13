#include "GameBoard.h"
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
    return getPacMan().getLives() == 0;
}

bool GameBoard::update() {
    if (isStarted()) {
        m_TimerGameLength.resume();
    } else {
        m_TimerGameLength.pause();
    }

    if (!isEnded()) {
        if (getGameMode()->shouldEnd())
            resetMode();

        spawnCherry();

        runScatter();

        /*if (isInvincible())
            m_TimerGameLengthInner.pause();
        else
            m_TimerGameLengthInner.resume();*/

        return updateGameMode(*this);
    } else {
        return false;
    }
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

void GameBoard::runScatter() {
    if (m_TimerGameLength.elapsed() >= 0 && m_TimerGameLength.elapsed() < 7) {
        runScatterMode(7);
    } else if (m_TimerGameLength.elapsed() == 27 && m_TimerGameLength.elapsed() < 34) {
        runScatterMode(7);
    } else if (m_TimerGameLength.elapsed() == 54 && m_TimerGameLength.elapsed() < 59) {
        runScatterMode(5);
    } else if (m_TimerGameLength.elapsed() == 79 && m_TimerGameLength.elapsed() < 84) {
        runScatterMode(5);
    }
}
