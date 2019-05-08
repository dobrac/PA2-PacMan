#include "GameBoard.h"
#include "../Exceptions/ExceptionPosNotFound.h"
#include "../Entities/Players/GhostYellow.h"
#include "../Entities/Players/GhostRed.h"

void GameBoard::setPacMan(const PacMan &pacman) {
    m_PacMan = pacman;
}

void GameBoard::addGhost(const std::shared_ptr<Ghost> &ghost) {
    m_Ghosts.push_back(ghost);
}

const std::vector<std::shared_ptr<Ghost>> &GameBoard::getGhosts() const {
    return m_Ghosts;
}

PacMan &GameBoard::getPacMan() {
    return m_PacMan;
}

GameMap &GameBoard::getMap() {
    return m_Map;
}

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

void GameBoard::initializeGhosts(const Pos &pos) {
    addGhost(std::make_shared<GhostYellow>(GhostYellow(pos, 200)));
    addGhost(std::make_shared<GhostRed>(GhostRed(pos, 50)));
}

bool GameBoard::isStarted() const {
    return m_PacMan.getVec() != Pos(0, 0) && !isEnded();
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

bool GameBoard::solveConflicts() {
    for (auto &ghost : m_Ghosts) {
        if (ghost->getPos() == m_PacMan.getPos()) {
            m_Lives--;
            m_PacMan.setVec({0, 0});
            m_PacMan.resetPos();
            for (auto &ghostRes : m_Ghosts) {
                ghostRes->resetPos();
            }
            return true;
        }
    }
    return false;
}