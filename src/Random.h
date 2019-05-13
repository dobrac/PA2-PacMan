#pragma once

#include <random>

/**
 * Class for getting random numbers
 */
class Random {
public:
    /**
     * Get random integer number using C++11 in range
     * @param from lower bound of range
     * @param to upper bound of range (inclusive)
     * @return random int value within the range
     */
    static int getInt(int from, int to);
};
