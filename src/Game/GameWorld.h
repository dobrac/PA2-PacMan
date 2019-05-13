#pragma once

#include "../Entities/Players/PacMan.h"
#include "../Entities/Players/Ghost.h"
#include "GameMap.h"

class GameWorld : public GameMap {
public:
    /**
     * Set PacMan to the world
     * @param pacman PacMan instance
     */
    void setPacMan(const PacMan &pacman);

    /**
     * Add Ghost to plane
     * @param ghost Ghost instance
     */
    void addGhost(const std::shared_ptr<Ghost> &ghost);

    /**
     * Get Ghosts in plane
     * @return vector of Ghosts
     */
    const std::vector<std::shared_ptr<Ghost>> &getGhosts() const;

    /**
     * Initialize Ghosts in plane at specific start position
     * @param pos Position to start on
     */
    void initializeGhosts(const Pos &pos);

    /**
     * Get PacMan instance
     * @return reference to PacMan instance
     */
    PacMan &getPacMan();

    /**
     * Get PacMan const instance
     * @return  reference to PacMan const instance
     */
    const PacMan &getPacMan() const;

    /**
     * Get Arrow queue of pressed keys
     * @return ArrowQueue reference
     */
    ArrowQueue &getArrowQueue();

private:
    /**
     * Variable for storing PacMan
     */
    PacMan m_PacMan = PacMan({0, 0});

    /**
     * Variable for storing ArrowQueue
     */
    ArrowQueue m_ArrowQueue;

    /**
     * Variable for string Ghosts
     */
    std::vector<std::shared_ptr<Ghost>> m_Ghosts;
};
