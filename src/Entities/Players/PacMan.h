#pragma once

#include "Player.h"

class GameBoard;

/**
 * PacMan class, overrides methods from Entity
 */
class PacMan : public Player {
public:
    /**
     * Constructs PacMan with speed
     * @param pos Position to start
     * @param speed Speed to start
     */
    explicit PacMan(const Pos &pos, int speed = 250);

    /**
     * Move PacMan on the plane
     * @param board reference to GameBord to play on
     * @return true if moved and should update
     */
    bool move(GameBoard &board);

    std::string print(const GameBoard &board) const override;

    EntityType getType() const override;

    /**
     * Get remaining lives of PacMan
     * @return lives
     */
    int getLives() const;

    /**
     * Remove lives from PacMan
     * @param count lives to remove
     */
    void removeLives(int count);

private:
    /**
     * Variable with lives
     */
    int m_Lives = 3;

    /**
     * Try to move PacMan to its direction position
     * @param board reference to GameBoard
     * @return true if moved
     */
    bool setMovePos(GameBoard &board);
};
