#include "GameWorld.h"
#include "../Entities/Players/GhostYellow.h"
#include "../Entities/Players/GhostRed.h"
#include "../Entities/Players/GhostBlue.h"

void GameWorld::setPacMan(const PacMan &pacman) {
    m_PacMan = pacman;
}

void GameWorld::addGhost(const std::shared_ptr<Ghost> &ghost) {
    m_Ghosts.push_back(ghost);
}


const std::vector<std::shared_ptr<Ghost>> &GameWorld::getGhosts() const {
    return m_Ghosts;
}

PacMan &GameWorld::getPacMan() {
    return m_PacMan;
}

void GameWorld::initializeGhosts(const Pos &pos) {
    addGhost(std::make_shared<GhostYellow>(GhostYellow(pos, 200)));
    addGhost(std::make_shared<GhostRed>(GhostRed(pos, 250)));
    addGhost(std::make_shared<GhostBlue>(GhostBlue(pos, 300)));
}

const PacMan &GameWorld::getPacMan() const {
    return m_PacMan;
}
