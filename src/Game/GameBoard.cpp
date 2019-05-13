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
    return !getPacMan().getVec().empty() && !isEnded();
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

        return updateGameMode(*this);
    } else {
        return false;
    }
}

double GameBoard::getGameLength() const {
    return m_TimerGameLength.elapsed();
}

void GameBoard::spawnCherry() {
    if (getPoinsGot() < getPointsMax() / 4) // check if has eaten at least 1/4 of the plane
        return;

    if (m_TimerNextCherry.elapsed() < TIME_MIN_CHERRY_SPAWN)
        return;

    int ranNum = Random::getInt(1, getCherryProbability()); // probability of spawning cherry
    if (ranNum != 1)
        return;

    std::vector<std::shared_ptr<Entity>> emptyEntities = getScreenEmpty(); // get empty entities
    if (emptyEntities.empty())
        return;

    int ranPos = Random::getInt(0, emptyEntities.size() - 1);

    Pos position = emptyEntities[ranPos]->getPos();
    removeScreenAt(position);
    addScreen(std::make_shared<Cherry>(Cherry(position)));

    m_TimerNextCherry.reset();
}

void GameBoard::runScatter() {
    /* if (m_TimerGameLength.elapsed() >= 0 && m_TimerGameLength.elapsed() < 7) {
         runScatterMode(7);
     } else if (m_TimerGameLength.elapsed() == 27 && m_TimerGameLength.elapsed() < 34) {
         runScatterMode(7);
     } else if (m_TimerGameLength.elapsed() == 54 && m_TimerGameLength.elapsed() < 59) {
         runScatterMode(5);
     } else if (m_TimerGameLength.elapsed() == 79 && m_TimerGameLength.elapsed() < 84) {
         runScatterMode(5);
     }*/
}

void GameBoard::addScore(int points) {
    m_Score += points;
}

int GameBoard::getScore() const {
    return m_Score;
}

int GameBoard::getLevel() const {
    return m_Level;
}

void GameBoard::incrementLevel() {
    if (!checkWinner())
        return;

    m_PointsGot = 0;

    getArrowQueue().clear();

    getPacMan().reset();

    for (auto &it : getGhosts()) {
        it->reset();
        it->setSpeed((int) (it->getSpeed() / getGhostSpeedMultiplier()));
    }

    resetScreen();

    m_Level++;
}
