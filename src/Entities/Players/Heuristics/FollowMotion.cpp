#include "FollowMotion.h"

#include "../../../Game/GameWorld.h"
#include <set>
#include <map>

// Follow PacMan
bool FollowMotion::chase(GameWorld &world, Player *ghost) {
    PacMan &pac = world.getPacMan();
    if (ghost->getPos() == pac.getPos()) {
        return false;
    }

    const Pos &nextPos = findNextPos(world, ghost->getPos(), pac.getPos());

    if (nextPos != Pos(0, 0))
        ghost->setPos(nextPos);

    return true;
}
