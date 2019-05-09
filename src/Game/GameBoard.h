#pragma once

#include "GameWorld.h"
#include "../Modes/Mode.h"
#include "../Modes/NormalMode.h"

class GameBoard : public GameWorld {
public:
    void addPointsMax(int count);
    void addPointsGot(int count);

    int getPointsMax() const;
    int getPoinsGot() const;

    bool isEnded() const;
    bool isStarted() const;
    bool checkWinner() const;
    bool checkLoser() const;

    int getLives() const;
    void removeLives(int count);

    const std::shared_ptr<Mode> & getGameMode() const;

    bool update();

    void runInvincibleMode();
    void resetMode();

    int getTimeChangeMode() const;

    bool isFrightened() const;

private:
    static const int TIME_INVINCIBLE_MODE = 10;

    int m_PointsMax = 0;
    int m_PointsGot = 0;

    int m_Lives = 3;

    Timer<Timer_Type_Second> m_TimerMode;

    std::shared_ptr<Mode> m_GameModeDefault = std::make_shared<NormalMode>(NormalMode());
    std::shared_ptr<Mode> m_GameModeToChange = m_GameModeDefault;

    /*
     * DO NOT SET DIRECTLY, only after update
     */
    std::shared_ptr<Mode> m_GameMode = m_GameModeDefault;
};


