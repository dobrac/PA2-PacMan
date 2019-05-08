#pragma once

#include "../ArrowQueue.h"
#include "../Entities/Entity.h"
#include <memory>
#include <vector>

class Entity;

class GameMap {
public:
    void addScreen(const std::shared_ptr<Entity> &entity);

    void setDimensions(int x, int y);

    int getX() const;

    int getY() const;

    const std::vector<std::shared_ptr<Entity>> &getScreen() const;

    const std::shared_ptr<Entity> &getScreenAt(const Pos &pos) const;
    void removeScreenAt(const Pos &pos);

    ArrowQueue &getArrowQueue();

private:
    int m_X = 0;
    int m_Y = 0;

    ArrowQueue m_ArrowQueue;

    std::vector<std::shared_ptr<Entity>> m_Screen;
};