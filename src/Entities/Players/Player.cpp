#include "Player.h"

Player::Player(const Pos &pos) : Entity(pos), m_DefaultPos(pos) {

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

Timer<Timer_Type_Millisecond> &Player::getTimer() {
    return m_Timer;
}

bool Player::setSpeed(int speed) {
    m_Speed = speed;
    return true;
}

int Player::getSpeed() const {
    return m_Speed;
}

void Player::resetPos() {
    setPos(m_DefaultPos);
}

bool Player::checkTimerMove(int speed) {
    if (speed == 0)
        speed = getSpeed();

    if (getTimer().elapsed() < speed) {
        return false;
    } else {
        getTimer().reset();
        return true;
    }
}
