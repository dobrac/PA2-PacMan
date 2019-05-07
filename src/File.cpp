#include "File.h"
#include "Entities/Border.h"
#include "Entities/Point.h"
#include "Entities/Empty.h"

#include <string>
#include <fstream>

const std::string File::MAPS_LOCATION = "maps/";

GameBoard File::loadBoard(const std::string &mapName) {
    std::string line;
    std::ifstream myfile(MAPS_LOCATION + mapName + ".pacmap");

    GameBoard board;

    if (myfile.is_open()) {
        int x = 0, y = 0;
        int xMax = 0;

        while (getline(myfile, line)) {
            for (const char it : line) {
                if (it == '.') {
                    board.getMap().addScreen(std::make_shared<Point>(Point({x, y})));
                    board.addPointsMax(1);
                } else if (it == ' ') {
                    board.getMap().addScreen(std::make_shared<Empty>(Empty({x, y})));
                } else if (it == '*') {
                    board.getMap().addScreen(std::make_shared<Border>(Border({x, y})));
                } else if (it == 'C') {
                    board.setPacMan(PacMan({x, y}));
                    board.getMap().addScreen(std::make_shared<Empty>(Empty({x, y})));
                } else if (it == 'G') {
                    board.initializeGhosts({x, y});
                    board.getMap().addScreen(std::make_shared<Empty>(Empty({x, y})));
                }
                //Console::print(std::string(1, it));
                x++;
            }
            //Console::printLine(" | " + std::to_string(x));
            y++;

            if (x > xMax)
                xMax = x;
            board.getMap().setDimensions(xMax, y);
            x = 0;
        }
        myfile.close();
    } else {
        // TODO: ERROR
    }
    return board;
}
