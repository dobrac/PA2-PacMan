#include "AheadMotion.h"

#include "../../../Game/GameWorld.h"
#include <set>
#include <map>

// Follow PacMan
bool AheadMotion::chase(GameWorld &world, Player *ghost) {
    PacMan &pac = world.getPacMan();
    if (ghost->getPos() == pac.getPos()) {
        return false;
    }

    Pos pacPos = pac.getPos();
    for (int i = 0; i < 4; i++) {
        std::shared_ptr<Entity> entLeft = world.getScreenAt(pacPos + pac.getVec());
        if (entLeft->getType() != Entity::EBorder)
            pacPos = entLeft->getPos();
        else
            break;
    }

    const Pos &nextPos = findNextPos(world, ghost->getPos(), pacPos);

    if (nextPos != Pos(0, 0)) {
        ghost->setPos(nextPos);
        return true;
    }

    return false;
}
