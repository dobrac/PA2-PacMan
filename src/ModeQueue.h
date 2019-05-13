#pragma once

#include <list>
#include "Modes/Mode.h"

/**
 * Class for handling game modes queue
 */
class ModeQueue {
public:
    /**
     * Add Mode to front of the queue
     * @param key Mode
     */
    void addFront(const std::shared_ptr<Mode> &mode);

    /**
     * Add Mode to queue
     * @param key Mode
     */
    void add(const std::shared_ptr<Mode> &mode);

    /**
     * Pop first from queue
     */
    void pop();

    /**
     * Print the queue
     */
    void print() const;

    /**
     * Get first Mode from the queue
     * @return const reference to first Mode
     */
    const std::shared_ptr<Mode> &get() const;

    /**
     * Check if the queue is empty
     * @return true if the queue is empty
     */
    bool empty() const;

    /**
     * Clears ModeQueue
     */
    void clear();

private:
    /**
     * List for storing queue Modes
     */
    std::list<std::shared_ptr<Mode>> m_Queue;
};
