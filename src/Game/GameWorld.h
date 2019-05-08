#pragma once

#include "../Entities/Players/PacMan.h"
#include "../Entities/Players/Ghost.h"

class GameWorld : public GameMap {
public:
    void setPacMan(const PacMan &pacman);

    void addGhost(const std::shared_ptr<Ghost> &ghost);

    const std::vector<std::shared_ptr<Ghost>> &getGhosts() const;

    void initializeGhosts(const Pos &pos);

    PacMan &getPacMan();

    const PacMan &getPacMan() const;

private:
    PacMan m_PacMan = PacMan({0, 0});

    std::vector<std::shared_ptr<Ghost>> m_Ghosts;
};
