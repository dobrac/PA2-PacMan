#include "CompletelyRandomMotion.h"

// Completely random potion
bool CompletelyRandomMotion::chase(GameMap &map, Player *ghost) {
    if (ghost->getTimer().elapsed() < ghost->getSpeed()) {
        return false;
    } else {
        ghost->getTimer().reset();
    }

    std::vector<std::shared_ptr<Entity>> directions;

    std::shared_ptr<Entity> entLeft = map.getScreenAt(ghost->getPos() + Pos(-1, 0));
    if (entLeft->getType() != Entity::EBorder)
        directions.push_back(entLeft);

    std::shared_ptr<Entity> entUp = map.getScreenAt(ghost->getPos() + Pos(0, -1));
    if (entUp->getType() != Entity::EBorder)
        directions.push_back(entUp);

    std::shared_ptr<Entity> entRight = map.getScreenAt(ghost->getPos() + Pos(1, 0));
    if (entRight->getType() != Entity::EBorder)
        directions.push_back(entRight);

    std::shared_ptr<Entity> entDown = map.getScreenAt(ghost->getPos() + Pos(0, 1));
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