#pragma once

#include "Game/GameBoard.h"
#include <string>

class File {
public:
    static GameBoard loadBoard(const std::string & mapName);

private:
    static const std::string MAPS_LOCATION;

    static bool integrityCheck(GameMap & map);
};