#pragma once

#include "GameWorld.h"
#include "../Modes/Mode.h"

class GameMode : public GameWorld {
public:

    bool updateGameMode(GameBoard &board);

    const std::shared_ptr<Mode> &getGameMode() const;

    void runScatterMode(int time);

    void runInvincibleMode();

    void resetMode();


    int getRemainingTimeMode() const;

    bool isInvincible() const;
    bool isScatter() const;

private:
    static const int TIME_INVINCIBLE_MODE = 10;

    std::shared_ptr<Mode> m_GameModeToChange = getDefaultMode();

    /*
     * DO NOT SET DIRECTLY, only after update
     */
    std::shared_ptr<Mode> m_GameMode = getDefaultMode();
};
