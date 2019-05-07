#include "GameMap.h"
#include "../Exceptions/ExceptionPosNotFound.h"

void GameMap::addScreen(const std::shared_ptr<Entity> &entity) {
    m_Screen.push_back(entity);
}

void GameMap::setDimensions(int x, int y) {
    m_X = x;
    m_Y = y;
}

int GameMap::getX() const {
    return m_X;
}

int GameMap::getY() const {
    return m_Y;
}

const std::vector<std::shared_ptr<Entity>> &GameMap::getScreen() const {
    return m_Screen;
}


const std::shared_ptr<Entity> &GameMap::getScreenAt(const Pos &pos) const {
    for (auto &it : m_Screen) {
        if (it->getPos() == pos)
            return it;
    }
    throw ExceptionPosNotFound();
}

ArrowQueue &GameMap::getArrowQueue() {
    return m_ArrowQueue;
}

void GameMap::removeScreenAt(const Pos &pos) {
    for (auto it = m_Screen.begin(); it != m_Screen.end(); ++it) {
        if ((*it)->getPos() == pos) {
            m_Screen.erase(it);
            break;
        }
    }
}
