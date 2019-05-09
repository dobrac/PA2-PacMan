#include "RandomMotion.h"

#include "../../../Game/GameWorld.h"
#include <vector>

// Random motion (goes straight)
bool RandomMotion::chase(GameWorld &world, Player *ghost) {
    std::vector<std::shared_ptr<Entity>> directions;

    Pos posLeft(-1, 0);
    Pos posUp(0, -1);
    Pos posRight(1, 0);
    Pos posDown(0, 1);

    std::shared_ptr<Entity> entLeft = world.getScreenAt(ghost->getPos() + posLeft);
    if (entLeft->getType() != Entity::EBorder && ghost->getVec() != posRight)
        directions.push_back(entLeft);

    std::shared_ptr<Entity> entUp = world.getScreenAt(ghost->getPos() + posUp);
    if (entUp->getType() != Entity::EBorder && ghost->getVec() != posDown)
        directions.push_back(entUp);

    std::shared_ptr<Entity> entRight = world.getScreenAt(ghost->getPos() + posRight);
    if (entRight->getType() != Entity::EBorder && ghost->getVec() != posLeft)
        directions.push_back(entRight);

    std::shared_ptr<Entity> entDown = world.getScreenAt(ghost->getPos() + posDown);
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