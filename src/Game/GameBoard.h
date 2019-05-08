#pragma once

#include "../Entities/Players/PacMan.h"
#include "../Entities/Players/Ghost.h"

class GameBoard {
public:
    void setPacMan(const PacMan &pacman);

    void addGhost(const std::shared_ptr<Ghost> &ghost);

    const std::vector<std::shared_ptr<Ghost>> &getGhosts() const;

    void initializeGhosts(const Pos & pos);

    PacMan &getPacMan();

    GameMap &getMap();

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
    PacMan m_PacMan = PacMan({0, 0});
    GameMap m_Map;

    int m_PointsMax = 0;
    int m_PointsGot = 0;

    int m_Lives = 3;

    std::vector<std::shared_ptr<Ghost>> m_Ghosts;
};


