#pragma once

#include "../Modes/Mode.h"
#include "../Modes/NormalMode.h"
#include <memory>
#include <map>

class GameSettings {
public:
    enum Difficulty {
        EASY,
        MEDIUM,
        HARD
    };

    void setDefaultDifficulty(const Difficulty &diff);

    void setDefaultMode(const std::shared_ptr<Mode> &mode);

    const Difficulty &getDefaultDifficulty() const;

    const std::shared_ptr<Mode> &getDefaultMode() const;

    static std::map<std::string, Difficulty> getDifficulties();

    static std::map<std::string, std::shared_ptr<Mode>> getModes();

private:
    Difficulty m_Difficulty = MEDIUM;
    std::shared_ptr<Mode> m_GameMode = std::make_shared<NormalMode>(NormalMode(0));
};