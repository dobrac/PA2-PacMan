#include "GameWorld.h"
#include "../Entities/Players/GhostYellow.h"
#include "../Entities/Players/GhostRed.h"
#include "../Entities/Players/GhostBlue.h"
#include "../Entities/Players/GhostGreen.h"

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
    double defaultMultiplier = 1;
    switch (getDefaultDifficulty()) {
        case EASY:
            defaultMultiplier = 0.8;
            break;
        case MEDIUM:
            defaultMultiplier = 1;
            break;
        case HARD:
            defaultMultiplier = 1.2;
            break;
    }


    addGhost(std::make_shared<GhostYellow>(GhostYellow(pos, (int) (250 / defaultMultiplier))));
    addGhost(std::make_shared<GhostRed>(GhostRed(pos, (int) (300 / defaultMultiplier))));
    addGhost(std::make_shared<GhostBlue>(GhostBlue(pos, (int) (400 / defaultMultiplier))));
    addGhost(std::make_shared<GhostGreen>(GhostGreen(pos, (int) (300 / defaultMultiplier))));
}

const PacMan &GameWorld::getPacMan() const {
    return m_PacMan;
}

ArrowQueue &GameWorld::getArrowQueue() {
    return m_ArrowQueue;
}