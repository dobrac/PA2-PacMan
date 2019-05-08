#pragma once

#include "GameWorld.h"

class GameBoard : public GameWorld {
public:
    void addPointsMax(int count);
    void addPointsGot(int count);

    int getPointsMax() const;
    int getPoinsGot() const;

    bool isEnded() const;
    bool isStarted() const;
    bool checkWinner() const;
    bool checkLoser() const;

    int getLives() const;

    bool solveConflicts();

private:
    int m_PointsMax = 0;
    int m_PointsGot = 0;

    int m_Lives = 3;
};


