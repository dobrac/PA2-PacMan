#include "CompletelyRandomMotion.h"

// Completely random potion
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

    /* generate secret number between 1 and 10: */
    int ran = rand() % directions.size() + 0;

    const Pos &dest = directions[ran]->getPos();

    ghost->setVec(ghost->getPos() - dest);
    ghost->setPos(dest);

    return true;
}