#include "PacMan.h"
#include "../Empty.h"

PacMan::PacMan(const Pos &pos, int speed) : Player(pos) {
    setSpeed(speed);
}

int PacMan::move(GameMap &map) {
    if (getTimer().elapsed() < getSpeed()) {
        return 0;
    } else {
        getTimer().reset();
    }

    int toReturn;

    Pos posVecBack = getVec();
    if (!map.getArrowQueue().empty()) {
        setVec(map.getArrowQueue().get());

        toReturn = setMovePos(map);
        if (toReturn > 0) {
            map.getArrowQueue().pop();
            return toReturn;
        }
    }

    setVec(posVecBack);
    toReturn = setMovePos(map);
    if (toReturn == 0 || posVecBack == Pos(0, 0)) {
        map.getArrowQueue().pop();
        return toReturn;
    }
    return toReturn;
}

std::string PacMan::print() const {
    if (m_Vec == Pos(1, 0))
        return "→";
    else if (m_Vec == Pos(-1, 0))
        return "←";
    else if (m_Vec == Pos(0, 1))
        return "↓";
    else if (m_Vec == Pos(0, -1))
        return "↑";
    else
        return "C";
}

Entity::EntityType PacMan::getType() const {
    return EPacMan;
}

int PacMan::setMovePos(GameMap &map) {
    std::shared_ptr<Entity> ent = map.getScreenAt(getDirection());

    if (ent->getType() == EEmpty) {
        m_Position = getDirection();
        return 1;
    }
    if (ent->getType() == EPoint) {
        map.removeScreenAt(getDirection());
        map.addScreen(std::make_shared<Empty>(Empty(getDirection())));
        m_Position = getDirection();
        return 2;
    }
    return 0;
}

