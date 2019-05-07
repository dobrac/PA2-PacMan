#include "RandomMotion.h"

// Random motion (goes straight)
bool RandomMotion::chase(GameMap &map, Player *ghost) {
    if (ghost->getTimer().elapsed() < ghost->getSpeed()) {
        return false;
    } else {
        ghost->getTimer().reset();
    }

    std::vector<std::shared_ptr<Entity>> directions;

    Pos posLeft(-1, 0);
    Pos posUp(0, -1);
    Pos posRight(1, 0);
    Pos posDown(0, 1);

    std::shared_ptr<Entity> entLeft = map.getScreenAt(ghost->getPos() + posLeft);
    if (entLeft->getType() != Entity::EBorder && ghost->getVec() != posRight)
        directions.push_back(entLeft);

    std::shared_ptr<Entity> entUp = map.getScreenAt(ghost->getPos() + posUp);
    if (entUp->getType() != Entity::EBorder && ghost->getVec() != posDown)
        directions.push_back(entUp);

    std::shared_ptr<Entity> entRight = map.getScreenAt(ghost->getPos() + posRight);
    if (entRight->getType() != Entity::EBorder && ghost->getVec() != posLeft)
        directions.push_back(entRight);

    std::shared_ptr<Entity> entDown = map.getScreenAt(ghost->getPos() + posDown);
    if (entDown->getType() != Entity::EBorder && ghost->getVec() != posUp)
        directions.push_back(entDown);

    if (directions.empty()) {
        ghost->setVec(ghost->getVec() * Pos(-1, -1)); // Revert direction
        return false;
    }

    if (directions.size() == 1) {
        if (directions[0]->getPos() - ghost->getPos() == ghost->getVec()
            || ghost->getPos() - directions[0]->getPos() == ghost->getVec()) {
            ghost->setPos(ghost->getDirection()); // Go straight in straight lines
            return true;
        }
    }

    /* generate secret number between directions.size() and 0: */
    int ran = rand() % directions.size() + 0;

    const Pos &dest = directions[ran]->getPos(); // Random destination

    ghost->setVec(ghost->getPos() - dest); // Compute vector to random destination
    ghost->setPos(dest);

    return true;
}