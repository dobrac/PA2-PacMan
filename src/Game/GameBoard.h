#pragma once

#include "GameMode.h"

class GameBoard : public GameMode {
public:
    bool update();

    void addPointsMax(int count);

    void addPointsGot(int count);


    int getPointsMax() const;

    int getPoinsGot() const;


    bool isEnded() const;

    bool isStarted() const;

    bool checkWinner() const;

    bool checkLoser() const;


    int getLives() const;

    void removeLives(int count);


    void runScatter();

    void spawnCherry();

    double getGameLength() const;

private:
    int m_PointsMax = 0;
    int m_PointsGot = 0;

    int m_Lives = 3;

    Timer<Timer_Type_Second, false> m_TimerGameLength;
    Timer<Timer_Type_Second> m_TimerGameLengthInner;
};


