#pragma once

#include "Game/GameBoard.h"
#include "Game/GameSettings.h"
#include <string>

class File {
public:
    static GameBoard loadBoard(const std::string &mapName);

private:
    static bool loadSettings(const std::string &fileName, GameBoard & board);

    static const std::string MAPS_LOCATION;
    static const std::string SETTINGS_LOCATION;

    static bool integrityCheck(GameMap &map);
};