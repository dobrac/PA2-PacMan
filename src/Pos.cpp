#include "Pos.h"

Pos::Pos(int x, int y) : m_X(x), m_Y(y) {
}

std::string Pos::operator()() const {
    return std::to_string(m_X) + ", " + std::to_string(m_Y);
}

int Pos::getX() const {
    return m_X;
}

int Pos::getY() const {
    return m_Y;
}

bool Pos::compare(int x, int y) const {
    return m_X == x && m_Y == y;
}

Pos &Pos::operator+=(const Pos &posAdd) {
    this->m_X += posAdd.m_X;
    this->m_Y += posAdd.m_Y;
    return *this;
}

Pos &Pos::operator-=(const Pos &posRemove) {
    this->m_X -= posRemove.m_X;
    this->m_Y -= posRemove.m_Y;
    return *this;
}

Pos &Pos::operator*=(const Pos &posMulti) {
    this->m_X = this->m_X * posMulti.m_X;
    this->m_Y = this->m_Y * posMulti.m_Y;
    return *this;
}

bool Pos::empty() const {
    return m_X == 0 && m_Y == 0;
}

bool Pos::operator==(const Pos &posCmp) const {
    return compare(posCmp.m_X, posCmp.m_Y);
}

Pos Pos::operator+(Pos posAdd) const {
    return posAdd += *this;
}

bool Pos::operator!=(const Pos &posCmp) const {
    return !(*this == posCmp);
}


Pos Pos::operator-(Pos posAdd) const {
    return posAdd -= *this;
}

Pos Pos::operator*(Pos posRemove) const {
    return posRemove *= *this;
}


