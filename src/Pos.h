#pragma once

#include <string>

/**
 * Class for storing coordinates X and Y
 */
class Pos {
public:
    /**
     * New instance of Pos with x and y values
     * @param x value for x coordinate
     * @param y value for y coordinate
     */
    Pos(int x, int y);

    /**
     * Compares x and y coordinates
     * @param x coordinate x
     * @param y coordinate y
     * @return true if coordinates x and y are same
     */
    bool compare(int x, int y) const;

    /**
     * Checks if coordinates are both zero
     * @return true if x=0 and y=0
     */
    bool empty() const;

    /**
     * Operator for getting x and y in string for printing
     * @return returns string with coordinates
     */
    std::string operator()() const;

    /**
     * Sum with different Pos
     * @param posAdd Pos to sum
     * @return this
     */
    Pos &operator+=(const Pos &posAdd);

    /**
     * Subtract different Pos
     * @param posRemove Pos to subtract
     * @return this
     */
    Pos &operator-=(const Pos &posRemove);

    /**
     * Multiply with different Pos
     * @param posMulti Pos to multiply with
     * @return this
     */
    Pos &operator*=(const Pos &posMulti);

    /**
     * Add two Pos instances together
     * @param posAdd Pos to add
     * @return new Pos instance
     */
    Pos operator+(Pos posAdd) const;

    /**
     * Subtract two Pos instances
     * @param posRemove Pos to subtract
     * @return new Pos instance
     */
    Pos operator-(Pos posRemove) const;

    /**
     * Multiply two Pos instances
     * @param posMulti Pos to multiply
     * @return new Pos instance
     */
    Pos operator*(Pos posMulti) const;

    /**
     * Compare with different Pos instance
     * @param posCmp Pos instance to compare
     * @return true if x and y are same
     */
    bool operator==(const Pos &posCmp) const;

    /**
     * Compare with different Pos instance
     * @param posCmp Pos instance to compare
     * @return true if x and y are not same
     */
    bool operator!=(const Pos &posCmp) const;

    /**
     * Compare with different Pos instance
     * @param pos  Pos instance to compare
     * @return true if parameter Y is bigger or same and parameter X is bigger
     */
    bool operator<(const Pos &pos) const;

    /**
     * Get x coordinate
     * @return x coordinate
     */
    int getX() const;

    /**
     * Get y coordinate
     * @return y coordinate
     */
    int getY() const;

private:
    /**
     * Variable x for storing x coordinate
     */
    int m_X;

    /**
     * Variable y for sotring y coordinate
     */
    int m_Y;
};
