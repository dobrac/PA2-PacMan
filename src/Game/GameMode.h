#pragma once

#include "GameWorld.h"
#include "../Modes/Mode.h"

/**
 * GameMode class for handling modes
 */
class GameMode : public GameWorld {
public:
    /**
     * Method for updating next Mode and handling Mode updates
     * @param board GameBoard reference to work with
     * @return true if screen should update
     */
    bool updateGameMode(GameBoard &board);

    /**
     * Get actual Mode
     * @return Mode
     */
    const std::shared_ptr<Mode> &getGameMode() const;

    /**
     * Run scatter mode for certain amount of time
     * @param time time to run the mode
     */
    void runScatterMode(int time);

    /**
     * Run invincible mode for predefined time
     */
    void runInvincibleMode();

    /**
     * Reset mode to default mode (from settings)
     */
    void resetMode();


    /**
     * Get remaining time of the actual mode
     * @return Remaining time in seconds, -1 if indefinite
     */
    int getRemainingTimeMode() const;

    /**
     * Check if its invincible mode
     * @return true if so
     */
    bool isInvincible() const;

    /**
     * Check if scatter mode
     * @return true if so
     */
    bool isScatter() const;

private:
    /**
     * Variable for storing mode that should change on next update
     */
    std::shared_ptr<Mode> m_GameModeToChange = getDefaultMode();

    /**
     * Variable for storing actual mode
     *
     * DO NOT SET DIRECTLY, only after update with GameModeToChange
     */
    std::shared_ptr<Mode> m_GameMode = getDefaultMode();
};
