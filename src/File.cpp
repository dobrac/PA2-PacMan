#include "File.h"
#include "Entities/Border.h"
#include "Entities/Point.h"
#include "Entities/Empty.h"
#include "Exceptions/ExceptionWrongMapFormat.h"
#include "Entities/Bonus.h"
#include "Exceptions/ExceptionWrongSettingFormat.h"
#include "Console.h"

#include <string>
#include <fstream>
#include <sstream>

const std::string File::MAPS_LOCATION("maps/");
const std::string File::SETTINGS_LOCATION("./");

GameBoard File::loadBoard(const std::string &mapName) {
    GameBoard board;

    board.setSettings(File::loadSettings("settings"));

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

        if (!integrityCheck(board))
            throw ExceptionWrongMapFormat();
    } else {
        throw ExceptionWrongMapFormat();
    }
    return board;
}

bool File::integrityCheck(GameMap &map) {
    for (auto &ent : map.getScreen()) {
        if (ent->getPos().getX() == 0)
            if (ent->getType() != Entity::EBorder)
                return false;

        if (ent->getPos().getY() == 0)
            if (ent->getType() != Entity::EBorder)
                return false;

        if (ent->getPos().getX() == map.getX())
            if (ent->getType() != Entity::EBorder)
                return false;

        if (ent->getPos().getY() == map.getY())
            if (ent->getType() != Entity::EBorder)
                return false;
    }

    return true;
}

Settings File::loadSettings(const std::string &fileName) {
    std::string line;
    std::ifstream myfile(SETTINGS_LOCATION + fileName + ".pacset");

    Settings set;

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            std::istringstream iss(line);

            std::string key;
            std::string word;
            if (!(iss >> key >> word)) {
                continue;
            }

            if (key == "Difficulty:") {
                auto mapDifficulties = Settings::getDifficulties();
                auto valueDifficulties = mapDifficulties.find(word);
                if (valueDifficulties != mapDifficulties.end()) {
                    set.setDifficulty(valueDifficulties->second);
                    Console::printLine("Loading Difficulty: " + std::to_string(valueDifficulties->second));
                    continue;
                }
            }

            if (key == "GameMode:") {
                auto mapGameModes = Settings::getGameModes();
                auto valueGameModes = mapGameModes.find(word);
                if (valueGameModes != mapGameModes.end()) {
                    set.setGameMode(valueGameModes->second);
                    Console::printLine("Loading GameMode: " + std::to_string(valueGameModes->second->getType()));
                    continue;
                }
            }
        }
        myfile.close();

    } else {
        //throw ExceptionWrongSettingFormat();
    }

    return set;
}
