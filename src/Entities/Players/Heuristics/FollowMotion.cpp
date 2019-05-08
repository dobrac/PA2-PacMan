#include "FollowMotion.h"

#include <set>

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

Pos FollowMotion::findNextPos(const GameWorld &world, const Pos &from, const Pos &to) {
    if (from == to) {
        return from;
    }

    std::list<TPosFind> toCheck;
    toCheck.push_back({from, nullptr});

    std::set<Pos> seen;

    Pos posLeft(-1, 0);
    Pos posUp(0, -1);
    Pos posRight(1, 0);
    Pos posDown(0, 1);

    while (!toCheck.empty()) {
        const TPosFind &posCheck = toCheck.front();

        if (seen.find(posCheck.m_Pos) == seen.end()) {
            if (posCheck.m_Pos == to) {
                TPosFind parent = posCheck;
                while (parent.m_PosFrom != nullptr && parent.m_PosFrom->m_PosFrom != nullptr) {
                    parent = *(parent.m_PosFrom);
                }
                return parent.m_Pos;
            }

            std::shared_ptr<Entity> entLeft = world.getScreenAt(posCheck.m_Pos + posLeft);
            if (entLeft->getType() != Entity::EBorder)
                toCheck.push_back({entLeft->getPos(), std::make_shared<TPosFind>(posCheck)});

            std::shared_ptr<Entity> entUp = world.getScreenAt(posCheck.m_Pos + posUp);
            if (entUp->getType() != Entity::EBorder)
                toCheck.push_back({entUp->getPos(), std::make_shared<TPosFind>(posCheck)});

            std::shared_ptr<Entity> entRight = world.getScreenAt(posCheck.m_Pos + posRight);
            if (entRight->getType() != Entity::EBorder)
                toCheck.push_back({entRight->getPos(), std::make_shared<TPosFind>(posCheck)});

            std::shared_ptr<Entity> entDown = world.getScreenAt(posCheck.m_Pos + posDown);
            if (entDown->getType() != Entity::EBorder)
                toCheck.push_back({entDown->getPos(), std::make_shared<TPosFind>(posCheck)});

            seen.emplace(posCheck.m_Pos);
        }
        toCheck.pop_front();
    }

    return {0, 0};
}