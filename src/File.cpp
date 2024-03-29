#include "File.h"
#include "Entities/Border.h"
#include "Entities/Point.h"
#include "Entities/Empty.h"
#include "Exceptions/ExceptionWrongMapFormat.h"
#include "Entities/Bonus.h"
#include "Console.h"

#include <string>
#include <fstream>
#include <sstream>

const std::string File::MAPS_LOCATION("examples/maps/");
const std::string File::SETTINGS_LOCATION("examples/");

GameBoard File::loadBoard(const std::string &mapName) {
    GameBoard board;

    File::loadSettings("settings", board);

    std::string line;
    std::ifstream myfile(MAPS_LOCATION + mapName + ".pacmap");

    if (myfile.is_open()) {
        int x = 0, y = 0;
        int xMax = 0;

        while (getline(myfile, line)) {
            for (const char it : line) {
                if (it == '.') {
                    board.addScreen(std::make_shared<Point>(Point({x, y})));
                    board.addPointsMax(1);
                } else if (it == ' ') {
                    board.addScreen(std::make_shared<Empty>(Empty({x, y})));
                } else if (it == '*') {
                    board.addScreen(std::make_shared<Border>(Border({x, y})));
                } else if (it == '%') {
                    board.addScreen(std::make_shared<Bonus>(Bonus({x, y})));
                    board.addPointsMax(1);
                } else if (it == 'C') {
                    board.setPacMan(PacMan({x, y}));
                    board.addScreen(std::make_shared<Empty>(Empty({x, y})));
                } else if (it == 'G') {
                    board.initializeGhosts({x, y});
                    board.addScreen(std::make_shared<Empty>(Empty({x, y})));
                }
                //Console::print(std::string(1, it));
                x++;
            }
            //Console::printLine(" | " + std::to_string(x));
            y++;

            if (x != xMax && xMax != 0) {
                myfile.close();
                throw ExceptionWrongMapFormat();
            } else {
                xMax = x;
            }
            board.setDimensions(xMax, y);
            x = 0;
        }
        myfile.close();

        if (xMax == 0 || y == 0)
            throw ExceptionWrongMapFormat();

        if (!integrityCheck(board))
            throw ExceptionWrongMapFormat();
    } else {
        throw ExceptionWrongMapFormat();
    }

    board.loadingDone();

    return board;
}

bool File::integrityCheck(GameWorld &map) {
    for (auto &ent : map.getScreen()) {
        if (ent->getPos().getX() == 0)
            if (ent->getType() != Entity::EBorder)
                return false;

        if (ent->getPos().getY() == 0)
            if (ent->getType() != Entity::EBorder)
                return false;

        if (ent->getPos().getX() == map.getX() - 1)
            if (ent->getType() != Entity::EBorder)
                return false;

        if (ent->getPos().getY() == map.getY() - 1)
            if (ent->getType() != Entity::EBorder)
                return false;
    }

    if (map.getPacMan().getPos() == Pos(0, 0))
        return false;

    return true;
}

bool File::loadSettings(const std::string &fileName, GameBoard &board) {
    std::string line;
    std::ifstream myfile(SETTINGS_LOCATION + fileName + ".pacset");

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            std::istringstream iss(line);

            std::string key;
            std::string word;
            if (!(iss >> key >> word)) {
                continue;
            }

            if (key == "Difficulty:") {
                auto mapDifficulties = GameSettings::getDifficulties();
                auto valueDifficulties = mapDifficulties.find(word);
                if (valueDifficulties != mapDifficulties.end()) {
                    board.setDefaultDifficulty(valueDifficulties->second);
                    Console::printLine("Loading Difficulty: " + word);
                    continue;
                }
            }

            if (key == "GameMode:") {
                auto mapGameModes = GameSettings::getModes();
                auto valueGameModes = mapGameModes.find(word);
                if (valueGameModes != mapGameModes.end()) {
                    board.setDefaultMode(valueGameModes->second);
                    Console::printLine("Loading GameMode: " + word);
                    continue;
                }
            }

            if (key == "CherryProbability:") {
                try {
                    board.setCherryProbability(std::stoi(word));
                    Console::printLine("Loading CherryProbability: " + word);
                } catch (std::invalid_argument &) {
                } catch (std::out_of_range &) {
                }
                continue;
            }

            if (key == "InvincibleModeLength:") {
                try {
                    board.setInvincibleModeLength(std::stoi(word));
                    Console::printLine("Loading InvincibleModeLength: " + word);
                } catch (std::invalid_argument &) {
                } catch (std::out_of_range &) {
                }
                continue;
            }

            if (key == "ScatterModeLength:") {
                try {
                    board.setScatterModeLength(std::stoi(word));
                    Console::printLine("Loading ScatterModeLength: " + word);
                } catch (std::invalid_argument &) {
                } catch (std::out_of_range &) {
                }
                continue;
            }

            if (key == "GhostSpeedIncrement:") {
                try {
                    board.setGhostSpeedMultiplier(std::stod(word));
                    Console::printLine("Loading GhostSpeedIncrement: " + word);
                } catch (std::invalid_argument &) {
                } catch (std::out_of_range &) {
                }
                continue;
            }
        }
        myfile.close();

    } else {
        return false;
    }

    return true;
}
