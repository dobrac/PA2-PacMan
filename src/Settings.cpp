#include "Settings.h"
#include "Modes/NormalMode.h"
#include "Modes/InvincibleMode.h"
#include "Modes/CrazyMode.h"

void Settings::setDifficulty(const Settings::Difficulty &diff) {
    m_Difficulty = diff;
}

void Settings::setGameMode(const std::shared_ptr<Mode> &mode) {
    m_GameMode = mode;
}

const Settings::Difficulty &Settings::getDifficulty() const {
    return m_Difficulty;
}

const std::shared_ptr<Mode> &Settings::getGameMode() const {
    return m_GameMode;
}

std::map<std::string, Settings::Difficulty> Settings::getDifficulties() {
    return std::map<std::string, Settings::Difficulty>(
            {
                    {"EASY",   EASY},
                    {"MEDIUM", MEDIUM},
                    {"HARD",   HARD}
            });
}

std::map<std::string, std::shared_ptr<Mode>> Settings::getGameModes() {
    return std::map<std::string, std::shared_ptr<Mode>>(
            {
                    {"NORMAL",     std::make_shared<NormalMode>(NormalMode())},
                    {"INVINCIBLE", std::make_shared<InvincibleMode>(InvincibleMode())},
                    {"CRAZY",      std::make_shared<CrazyMode>(CrazyMode())}
            });
}
