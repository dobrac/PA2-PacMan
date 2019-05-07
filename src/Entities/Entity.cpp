#include "Entity.h"


Entity::Entity(const Pos &pos) : m_Position(pos) {

}

const Pos & Entity::getPos() const {
    return m_Position;
}

bool Entity::intersects(const Entity &ent) const {
    return m_Position == ent.getPos();
}

void Entity::setPos(const Pos &pos) {
    m_Position = pos;
}
