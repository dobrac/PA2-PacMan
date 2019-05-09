#pragma once

#include "Game/GameBoard.h"
#include "Settings.h"
#include <string>

class File {
public:
    static GameBoard loadBoard(const std::string &mapName);

    static Settings loadSettings(const std::string &fileName);

private:
    static const std::string MAPS_LOCATION;
    static const std::string SETTINGS_LOCATION;

    static bool integrityCheck(GameMap &map);
};