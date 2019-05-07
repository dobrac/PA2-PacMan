#include "Game.h"

#include "Entities/Players/PacMan.h"
#include "Entities/Border.h"
#include "Entities/Point.h"
#include "File.h"

#include <thread>

using namespace std;

Game::Game() {
    startMenu();
}

void Game::showMenu() const {
    printLine("Welcome to PacMan");
    printLine("1) Start Game ('s')");
    printLine("2) Exit Game ('e')");
}

void Game::showGame() {
    if (m_ShouldUpdate) {
        // Clear console
        clear();

        const int mapX = getMap().getX();
        const int mapY = getMap().getY();

        // Reserve size for screen
        std::vector<std::vector<std::string>> screen;
        screen.reserve(mapX);
        screen.resize(mapX);
        for (auto &it : screen) {
            it.reserve(mapY);
            it.resize(mapY);
        }

        // Show screen entities
        for (auto &ent : getMap().getScreen()) {
            screen[ent->getPos().getX()][ent->getPos().getY()] = ent->print();
        }

        // Show ghosts
        for (auto &ent : getBoard().getGhosts()) {
            screen[ent->getPos().getX()][ent->getPos().getY()] = ent->print();
        }

        // Show PacMan
        screen[getBoard().getPacMan().getPos().getX()][getBoard().getPacMan().getPos().getY()] = getBoard().getPacMan().print();

        // Print Score
        printLine(
                "Score: " + std::to_string(getBoard().getPoinsGot()) + "/" + std::to_string(getBoard().getPointsMax()));

        // Print Board
        for (int y = 0; y < getMap().getY(); y++) {
            for (int x = 0; x < getMap().getX(); x++) {
                print(screen[x][y]);
            }
            printLine();
        }

        m_ShouldUpdate = false;

        // Check winner
        if (getBoard().checkWinner()) {
            printLine("Winner! Game ended. (Press 'e' to exit.)");
            return;
        }

        // Debug arrow queue
        getMap().getArrowQueue().print();
    }

    if (!getBoard().isEnded()){
        // Move Ghosts
        for (auto &ghost : getBoard().getGhosts()) {
            if (ghost->chase(getMap())) {
                m_ShouldUpdate = true;
            }
        }

        // Move PacMan
        int pac = getBoard().getPacMan().move(getMap());
        if (pac == 2) {
            getBoard().addPointsGot(1);
        }
        if (pac > 0) {
            m_ShouldUpdate = true;
        }
    }
}

bool Game::runGameLoop() {
    ARROW keyPressed = getArrow();
    switch (keyPressed) {
        case LEFT:
            getMap().getArrowQueue().add(Pos(-1, 0));
            break;
        case RIGHT:
            getMap().getArrowQueue().add(Pos(1, 0));
            break;
        case UP:
            getMap().getArrowQueue().add(Pos(0, -1));
            break;
        case DOWN:
            getMap().getArrowQueue().add(Pos(0, 1));
            break;
        case END:
            endGame();
            startMenu();
            return false;
        case ARROW_OTHER:
            break;
    }
    return true;
}

bool Game::runMenuLoop() {
    MENU keyPressed = getMenu();
    switch (keyPressed) {
        case START:
            printLine("Starting game...");
            startGame();
            return false;
        case EXIT:
            printLine("Exiting game...");
            return false;
        case MENU_OTHER:
            break;
    }
    return true;
}


void Game::startMenu() {
    showMenu();
    while (runMenuLoop()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void Game::startGame() {
    m_Board = File::loadBoard("basic");

    while (runGameLoop()) {
        showGame();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void Game::endGame() {
    printLine("Ending game...");
}

GameMap &Game::getMap() {
    return m_Board.getMap();
}

GameBoard &Game::getBoard() {
    return m_Board;
}
