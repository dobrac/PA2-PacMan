#include "Game.h"

#include "Entities/Players/PacMan.h"
#include "Entities/Border.h"
#include "Entities/Point.h"
#include "File.h"
#include "Exceptions/ExceptionWrongMapFormat.h"

#include <thread>

using namespace std;

Game::Game() {
    startMenu();
}

void Game::showMenu() const {
    printLine("Welcome to PacMan");
    printLine("1) Start BASIC Game ('s')");
    printLine("2) Start MEDIUM Game ('m')");
    printLine("3) Exit Game ('e')");
}

void Game::showScore() const {
    print("Points: ");
    print(std::to_string(getBoard().getPoinsGot()));
    print("/");
    print(std::to_string(getBoard().getPointsMax()));
    print(" | ");
    print("Lives: ");
    print(std::to_string(getBoard().getLives()));
    printLine();

    print("Mode: ");
    print(getBoard().getGameMode()->print());
    if (getBoard().getTimeChangeMode() != -1) {
        print(" | ");
        print("Next change: ");
        print(std::to_string(getBoard().getTimeChangeMode()) + "s");
    }
    printLine();

    print("Performance (TPS): ");
    print(std::to_string(m_TPS));
    print("/");
    print("20");
    printLine();
}


bool Game::checkEnd() const {
    // Check winner
    if (getBoard().checkWinner()) {
        printLine("Winner! Game ended. (Press 'e' to exit.)");
        return true;
    }

    // Check loser
    if (getBoard().checkLoser()) {
        printLine("Loser! Game ended. (Press 'e' to exit.)");
        return true;
    }

    return false;
}


void Game::showScreen() const {
    // Clear console
    clear();

    const int mapX = getBoard().getX();
    const int mapY = getBoard().getY();

    // Reserve size for screen
    std::vector<std::vector<std::string>> screen;
    screen.reserve(mapX);
    screen.resize(mapX);
    for (auto &it : screen) {
        it.reserve(mapY);
        it.resize(mapY);
    }

    // Show screen entities
    for (auto &ent : getBoard().getScreen()) {
        screen[ent->getPos().getX()][ent->getPos().getY()] = ent->print(getBoard());
    }

    // Show ghosts
    for (auto &ent : getBoard().getGhosts()) {
        screen[ent->getPos().getX()][ent->getPos().getY()] = ent->print(getBoard());
    }

    // Show PacMan
    screen[getBoard().getPacMan().getPos().getX()][getBoard().getPacMan().getPos().getY()]
            = getBoard().getPacMan().print(getBoard());

    // Print Score
    showScore();

    // Print Board
    for (int y = 0; y < getBoard().getY(); y++) {
        for (int x = 0; x < getBoard().getX(); x++) {
            print(screen[x][y]);
        }
        printLine();
    }
}


void Game::showGame() {
    if (m_ShouldUpdate) {
        showScreen();

        m_ShouldUpdate = false;

        // Check end
        if (checkEnd())
            return;
    }

    if (getBoard().update())
        m_ShouldUpdate = true;
}

bool Game::runGameLoop() {
    ARROW keyPressed = getArrow();
    switch (keyPressed) {
        case LEFT:
            getBoard().getArrowQueue().add(Pos(-1, 0));
            break;
        case RIGHT:
            getBoard().getArrowQueue().add(Pos(1, 0));
            break;
        case UP:
            getBoard().getArrowQueue().add(Pos(0, -1));
            break;
        case DOWN:
            getBoard().getArrowQueue().add(Pos(0, 1));
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
        case START_B:
            printLine("Starting BASIC game...");
            startGame("basic");
            return false;
        case START_M:
            printLine("Starting MEDIUM game...");
            startGame("medium");
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

void Game::startGame(const std::string &mapName) {
    try {
        m_Board = File::loadBoard(mapName);
    } catch (ExceptionWrongMapFormat &) {
        printLine("ERROR: Map has wrong format.");
        startMenu();
        return;
    }

    Timer<Timer_Type_Millisecond> tps;
    int count = 0;
    while (runGameLoop()) {
        showGame();

        if (tps.elapsed() >= 1000) {
            m_TPS = count;
            tps.reset();
            count = 0;
        }
        count++;

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void Game::endGame() {
    printLine("Ending game...");
}

GameBoard &Game::getBoard() {
    return m_Board;
}

const GameBoard &Game::getBoard() const {
    return m_Board;
}
