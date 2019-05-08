#pragma once

#include "../Entity.h"
#include "../../Pos.h"
#include "../../Timer.h"

class Player : public Entity {
public:
    Player(const Pos &pos);

    void setVec(const Pos &vec);

    const Pos &getVec() const;

    Pos getDirection() const;

    Timer<Timer_Type_Millisecond> & getTimer();

    bool setSpeed(int speed);
    int getSpeed() const;

    void resetPos();

    bool checkTimerMove(int speed = 0);

protected:
    Pos m_Vec = Pos(0, 0);

    Pos m_DefaultPos;

    Timer<Timer_Type_Millisecond> m_Timer;
    int m_Speed = 0;
};
