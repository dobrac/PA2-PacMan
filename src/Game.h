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

    GameMap &getMap();

    GameBoard &getBoard();


private:
    GameBoard m_Board;
    bool m_ShouldUpdate = true;

    void showMenu() const;

    void showGame();

    bool runGameLoop();

    bool runMenuLoop();

    void startMenu();

    void startGame();

    void endGame();
};
