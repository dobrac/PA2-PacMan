#pragma once

#include "../Entity.h"
#include "../../Game/GameMap.h"
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

protected:
    Pos m_Vec = Pos(0, 0);

    Pos m_DefaultPos;

    Timer<Timer_Type_Millisecond> m_Timer;
    int m_Speed = 0;
};
