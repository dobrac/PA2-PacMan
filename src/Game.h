#pragma once

#include "Console.h"
#include "Pos.h"
#include "Entities/Entity.h"
#include "Entities/Players/Player.h"
#include "Entities/Players/PacMan.h"
#include "Game/GameBoard.h"
#include "Timer.h"

#include <list>
#include <vector>
#include <memory>

/**
 * Game class to manage game and menu
 */
class Game : public Console {
public:

    /**
     * Construct new Game and show main menu
     */
    Game();

    /**
     * Get GameBoard with game running
     * @return GameBoard reference to local instance
     */
    GameBoard &getBoard();

    /**
     * Get constant GameBoard with game running
     * @return  GameBoard const reference to local instance
     */
    const GameBoard &getBoard() const;


private:
    /**
     * Running GameBoard instance
     */
    GameBoard m_Board;

    /**
     * Variable to handle console refreshes
     */
    bool m_ShouldUpdate = true;

    /**
     * TPS counter
     */
    int m_TPS = 20;

    /**
     * Show main menu, print it
     */
    void showMenu() const;

    /**
     * Show and update Game, print it
     */
    void showGame();

    /**
     * Show Game plane
     */
    void showScreen() const;

    /**
     * Show Game score
     */
    void showScore() const;

    /**
     * Check if the game has ended and show message
     * @return true if the game has ended
     */
    bool checkEnd() const;

    /**
     * Get input from user, save it or run specific next methods
     * @return true if any key, false if end key was pressed
     */
    bool runGameLoop();

    /**
     * Get input from user and run specific next methods
     * @return true if any key, false if specific keys
     */
    bool runMenuLoop();

    /**
     * Run menu loop and read keys
     */
    void startMenu();

    /**
     * Start Game, loads map, settings and runs Game loop
     * @param mapName name of the map
     */
    void startGame(const std::string &mapName);

    /**
     * Ends the Game, shows message
     */
    void endGame();
};
