#pragma once

#include "../ArrowQueue.h"
#include "../Entities/Entity.h"
#include "GameSettings.h"
#include <memory>
#include <vector>
#include <map>

/**
 * Class for map handling
 */
class GameMap : public GameSettings {
public:
    /**
     * Add Entity to screen
     * @param entity to add
     */
    void addScreen(const std::shared_ptr<Entity> &entity);

    /**
     * Set map dimensions
     * @param x value
     * @param y value
     */
    void setDimensions(int x, int y);

    /**
     * Get x dimension
     * @return x value
     */
    int getX() const;

    /**
     * Get y dimension
     * @return y value
     */
    int getY() const;

    /**
     * Get Entities forming screen
     * @return Entities
     */
    const std::vector<std::shared_ptr<Entity>> &getScreen() const;

    /**
     * Get Empty screen Entities
     * @return vector of Empty screen Entities
     */
    std::vector<std::shared_ptr<Entity>> getScreenEmpty() const;

    /**
     * Get entity at specific position
     * @param pos Position to find
     * @return Entity
     */
    const std::shared_ptr<Entity> &getScreenAt(const Pos &pos) const;

    /**
     * Remove Entity at specific position
     * @param pos Pos to find and remove
     */
    void removeScreenAt(const Pos &pos);

    /**
     * Get map from Entities, useful for many searches in short time (e.g. Follow Motion)
     * @return Map of <Pos, Entity>
     */
    std::map<Pos, std::shared_ptr<Entity>> getScreenMap() const;

    /**
     * Get entity at certaing position in the referenced map
     * @param entities Map with Entities
     * @param pos Position to find
     * @return Entity
     */
    static const std::shared_ptr<Entity> &
    getScreenAt(const std::map<Pos, std::shared_ptr<Entity>> &entities, const Pos &pos);


private:
    /**
     * Variable for storing x dimension
     */
    int m_X = 0;

    /**
     * Variable for storing y dimension
     */
    int m_Y = 0;

    /**
     * Vector for storing all screen entities
     */
    std::vector<std::shared_ptr<Entity>> m_Screen;
};