#include "Entity.h"


Entity::Entity(const Pos &pos) : m_Position(pos) {

}

const Pos & Entity::getPos() const {
    return m_Position;
}

void Entity::setPos(const Pos &pos) {
    m_Position = pos;
}

bool Entity::operator<(const Entity &ent) {
    return this->getPos() < ent.getPos();
}

void Entity::remove(GameBoard &) {
}
