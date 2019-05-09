#pragma once

#include "Modes/Mode.h"
#include "Modes/NormalMode.h"
#include <memory>
#include <map>

class Settings {
public:
    enum Difficulty {
        EASY,
        MEDIUM,
        HARD
    };

    void setDifficulty(const Difficulty &diff);

    void setGameMode(const std::shared_ptr<Mode> &mode);

    const Difficulty &getDifficulty() const;

    const std::shared_ptr<Mode> &getGameMode() const;

    static std::map<std::string, Difficulty> getDifficulties();

    static std::map<std::string, std::shared_ptr<Mode>> getGameModes();

private:
    Difficulty m_Difficulty = MEDIUM;
    std::shared_ptr<Mode> m_GameMode = std::make_shared<NormalMode>(NormalMode());
};