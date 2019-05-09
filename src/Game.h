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

class Game : public Console {
public:
    Game();

    GameBoard &getBoard();

    const GameBoard &getBoard() const;


private:
    GameBoard m_Board;
    bool m_ShouldUpdate = true;

    int m_TPS = 20;

    void showMenu() const;

    void showGame();

    void showScreen() const;

    void showScore() const;

    bool checkEnd() const;

    bool runGameLoop();

    bool runMenuLoop();

    void startMenu();

    void startGame(const std::string &mapName);

    static void endGame();
};
