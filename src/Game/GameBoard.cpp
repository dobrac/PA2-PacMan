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

bool GameBoard::isEnded() const {
    return getPoinsGot() == getPointsMax();
}

bool GameBoard::checkWinner() const {
    return isEnded();
}
