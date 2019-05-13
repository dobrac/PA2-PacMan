#pragma once

#include "../Modes/Mode.h"
#include "../Modes/NormalMode.h"
#include <memory>
#include <map>

/**
 * Class for handling Game Settings
 */
class GameSettings {
public:
    /**
     * Enum with difficulties
     */
    enum Difficulty {
        EASY,
        MEDIUM,
        HARD
    };

    /**
     * Set default difficulty
     * @param diff difficulty to set
     */
    void setDefaultDifficulty(const Difficulty &diff);

    /**
     * Set default mode
     * @param mode mode to set
     */
    void setDefaultMode(const std::shared_ptr<Mode> &mode);

    /**
     * Get default difficulty
     * @return difficulty from enum
     */
    const Difficulty &getDefaultDifficulty() const;

    /**
     * Get default mode
     * @return default mode
     */
    const std::shared_ptr<Mode> &getDefaultMode() const;

    /**
     * Get Map of difficulties for config loading
     * @return map of difficulties
     */
    static std::map<std::string, Difficulty> getDifficulties();

    /**
     * Get map of modes for config loading
     * @return map of modes
     */
    static std::map<std::string, std::shared_ptr<Mode>> getModes();

    /**
     * Set Cherry spawn probability
     * @param probability probability to set
     */
    void setCherryProbability(int probability);

    /**
     * Get Cherry spawn probability
     * @return probability max range
     */
    int getCherryProbability() const;

    /**
     * Set Ghost speed multiplier
     * @param multiplier multiplier to set
     */
    void setGhostSpeedMultiplier(double multiplier);

    /**
     * Get Ghost speed multiplier
     * @return multiplier
     */
    double getGhostSpeedMultiplier() const;

    /**
     * Set Invincible Mode length
     * @param length length to set in seconds
     */
    void setInvincibleModeLength(int length);

    /**
     * Get Invincible Mode length
     * @return mode length in seconds
     */
    int getInvincibleModeLength() const;

    /**
     * Set Scatter Mode length
     * @param length length to set in seconds
     */
    void setScatterModeLength(int length);

    /**
     *  Get Scatter Mode length
     * @return mode length in seconds
     */
    int getScatterModeLength() const;

private:
    /**
     * Variable for storing difficulty
     */
    Difficulty m_Difficulty = MEDIUM;

    /**
     * Variable for storing mode
     */
    std::shared_ptr<Mode> m_GameMode = std::make_shared<NormalMode>(NormalMode(0));

    /**
     * Variable for storing Cherry spawn probability
     */
    int m_CherryProbability = 10;

    /**
     * Variable for incrementing ghost speed on level up
     */
    double m_GhostSpeedMultiplier = 1.001;

    /**
     * Variable for Invincible Mode length
     */
    int m_InvincibleModeLength = 10;

    /**
     * Variable for Scatter Mode length
     */
    int m_ScatterModeLength = 7;
};