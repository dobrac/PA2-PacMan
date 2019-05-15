#pragma once

#include "Game/GameBoard.h"
#include "Game/GameSettings.h"
#include <string>

/**
 * File class for loading map and game settings from files
 */
class File {
public:

    /**
     * Load GameBoard from file
     * @param mapName Map name to load
     * @return
     */
    static GameBoard loadBoard(const std::string &mapName);

private:
    /**
     * Load settings from file
     * @param fileName Settings file name to load
     * @param board GameBoard object for saving settings
     * @return true if settings were successfully loaded
     */
    static bool loadSettings(const std::string &fileName, GameBoard & board);

    /**
     * Maps default location in file system
     */
    static const std::string MAPS_LOCATION;

    /**
     * Settings default location in file system
     */
    static const std::string SETTINGS_LOCATION;

    /**
     * Check if map meets certain requirements (ends with border on each side)
     * @param map GameWorld object for check
     * @return true if all checks has passed
     */
    static bool integrityCheck(GameWorld &map);
};