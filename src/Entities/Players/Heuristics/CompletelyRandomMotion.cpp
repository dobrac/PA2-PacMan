#include "CompletelyRandomMotion.h"

#include "../../../Game/GameWorld.h"
#include "../../../Random.h"
#include <vector>

// Completely random motion
bool CompletelyRandomMotion::chase(GameWorld &world, Player *ghost) {
    std::vector<std::shared_ptr<Entity>> directions;

    std::shared_ptr<Entity> entLeft = world.getScreenAt(ghost->getPos() + Pos(-1, 0));
    if (entLeft->getType() != Entity::EBorder)
        directions.push_back(entLeft);

    std::shared_ptr<Entity> entUp = world.getScreenAt(ghost->getPos() + Pos(0, -1));
    if (entUp->getType() != Entity::EBorder)
        directions.push_back(entUp);

    std::shared_ptr<Entity> entRight = world.getScreenAt(ghost->getPos() + Pos(1, 0));
    if (entRight->getType() != Entity::EBorder)
        directions.push_back(entRight);

    std::shared_ptr<Entity> entDown = world.getScreenAt(ghost->getPos() + Pos(0, 1));
    if (entDown->getType() != Entity::EBorder)
        directions.push_back(entDown);

    if (directions.empty())
        return false;

    /* generate secret number between directions.size() and 0: */
    int ran = Random::getInt(0, directions.size() - 1);

    const Pos &dest = directions[ran]->getPos();

    ghost->setVec(ghost->getPos() - dest);
    ghost->setPos(dest);

    return true;
}