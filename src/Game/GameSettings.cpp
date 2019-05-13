#include "GameSettings.h"
#include "../Modes/NormalMode.h"
#include "../Modes/InvincibleMode.h"
#include "../Modes/CrazyMode.h"

void GameSettings::setDefaultDifficulty(const GameSettings::Difficulty &diff) {
    m_Difficulty = diff;
}

void GameSettings::setDefaultMode(const std::shared_ptr<Mode> &mode) {
    m_GameMode = mode;
}

const GameSettings::Difficulty &GameSettings::getDefaultDifficulty() const {
    return m_Difficulty;
}

const std::shared_ptr<Mode> &GameSettings::getDefaultMode() const {
    return m_GameMode;
}

std::map<std::string, GameSettings::Difficulty> GameSettings::getDifficulties() {
    return std::map<std::string, GameSettings::Difficulty>(
            {
                    {"EASY",   EASY},
                    {"MEDIUM", MEDIUM},
                    {"HARD",   HARD}
            });
}

std::map<std::string, std::shared_ptr<Mode>> GameSettings::getModes() {
    return std::map<std::string, std::shared_ptr<Mode>>(
            {
                    {"NORMAL",     std::make_shared<NormalMode>(NormalMode(0))},
                    {"INVINCIBLE", std::make_shared<InvincibleMode>(InvincibleMode(0))},
                    {"CRAZY",      std::make_shared<CrazyMode>(CrazyMode(0))}
            });
}

int GameSettings::getCherryProbability() const {
    return m_CherryProbability;
}

double GameSettings::getGhostSpeedMultiplier() const {
    return m_GhostSpeedMultiplier;
}

void GameSettings::setCherryProbability(int probability) {
    m_CherryProbability = probability;
}

void GameSettings::setGhostSpeedMultiplier(double multiplier) {
    m_GhostSpeedMultiplier = multiplier;
}

void GameSettings::setInvincibleModeLength(int length) {
    m_InvincibleModeLength = length;
}

int GameSettings::getInvincibleModeLength() const {
    return m_InvincibleModeLength;
}

void GameSettings::setScatterModeLength(int length) {
    m_ScatterModeLength = length;
}

int GameSettings::getScatterModeLength() const {
    return m_ScatterModeLength;
}


