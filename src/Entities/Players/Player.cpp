#include "Player.h"

Player::Player(const Pos &pos) : Entity(pos) {

}

void Player::setVec(const Pos &vec) {
    m_Vec = vec;
}

const Pos &Player::getVec() const {
    return m_Vec;
}

Pos Player::getDirection() const {
    return m_Position + m_Vec;
}

Timer<Timer_Type_Millisecond> & Player::getTimer() {
    return m_Timer;
}

bool Player::setSpeed(int speed) {
    m_Speed = speed;
    return true;
}

int Player::getSpeed() const {
    return m_Speed;
}
