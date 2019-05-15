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
    print("Time in game: ");
    print(std::to_string((int) getBoard().getGameLength()) + "s");
    printLine();

    print("Score: ");
    print(std::to_string(getBoard().getScore()));
    print(" | ");
    print("Level: ");
    print(std::to_string(getBoard().getLevel()));
    printLine();

    print("Points: ");
    print(std::to_string(getBoard().getPoinsGot()));
    print("/");
    print(std::to_string(getBoard().getPointsMax()));
    print(" | ");
    print("Lives: ");
    print(std::to_string(getBoard().getPacMan().getLives()));
    printLine();

    print("Difficulty: ");
    switch (getBoard().getDefaultDifficulty()) {
        case GameMap::EASY:
            print("EASY");
            break;
        case GameMap::MEDIUM:
            print("MEDIUM");
            break;
        case GameMap::HARD:
            print("HARD");
            break;
    }
    print(" | ");
    print("Mode: ");
    print(getBoard().getGameMode()->print());
    if (getBoard().getRemainingTimeMode() != -1) {
        print(" | ");
        print("Next change: ");
        print(std::to_string(getBoard().getRemainingTimeMode()) + "s");
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
        printLine("Winner! Game ended. (Press 'n' to next level or 'e' to exit)");
        return true;
    }

    // Check loser
    if (getBoard().checkLoser()) {
        printLine("Loser! Game ended. (Press 'e' to exit.)");
        return true;
    }

    return false;
}

std::vector<std::vector<std::string>> Game::getScreen() const {
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

    return screen;
}


void Game::showScreen(const std::vector<std::vector<std::string>> &screen) const {
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
        // Generate screen, can take longer time
        std::vector<std::vector<std::string>> screen = getScreen();

        // Clear console
        clear();

        // Print Score
        showScore();

        // Print Board
        showScreen(screen);

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
        case NEXT_LEVEL:
            getBoard().incrementLevel();
            m_ShouldUpdate = true;
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

    // TPS counter
    Timer<Timer_Type_Millisecond> tpsTimer;
    int tpsCount = 0;

    // Lag solver
    Timer<Timer_Type_Millisecond> gameLagSolver;
    while (runGameLoop()) {
        gameLagSolver.reset();

        showGame();

        if (tpsTimer.elapsed() >= 1000) {
            m_TPS = tpsCount;
            tpsTimer.reset();
            tpsCount = 0;
        }
        tpsCount++;

        int diff = 50 - (int) gameLagSolver.elapsed();
        if (diff > 0)
            std::this_thread::sleep_for(std::chrono::milliseconds(diff));
    }
}

void Game::endGame() {
    printLine("Ending game...");
    m_ShouldUpdate = true;
}

GameBoard &Game::getBoard() {
    return m_Board;
}

const GameBoard &Game::getBoard() const {
    return m_Board;
}
