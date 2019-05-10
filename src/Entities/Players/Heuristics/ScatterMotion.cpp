#include "ScatterMotion.h"

#include "../../../Game/GameWorld.h"
#include "../../../Random.h"
#include <vector>

// Home motion
bool ScatterMotion::chase(GameWorld &world, Player *ghost) {
    PacMan &pac = world.getPacMan();
    if (ghost->getPos() == pac.getPos()) {
        return false;
    }

    const Pos &nextPos = findNextPos(world, ghost->getPos(), ghost->getDefaultPos());

    if (nextPos != Pos(0, 0))
        ghost->setPos(nextPos);

    return true;
}