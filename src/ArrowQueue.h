#pragma once

#include "Pos.h"
#include <list>

/**
 * Class for handling arrow key presses queue
 */
class ArrowQueue {
public:
    /**
     * Add Pos vector to queue
     * @param key Pos vector
     */
    void add(const Pos &key);

    /**
     * Pop first from queue
     */
    void pop();

    /**
     * Print the queue
     */
    void print() const;

    /**
     * Get first Pos from the queue
     * @return const reference to first Pos
     */
    const Pos &get() const;

    /**
     * Check if the queue is empty
     * @return true if the queue is empty
     */
    bool empty() const;

    /**
     * Clears ArrowQueue
     */
    void clear();

private:
    /**
     * List for storing queue Pos
     */
    std::list<Pos> m_Queue;
};
