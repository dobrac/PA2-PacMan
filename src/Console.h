#pragma once

#include <string>

/**
 * Class for printing strings and reading user inputs
 */
class Console {
public:
    /**
     * Enum for arrow keys and game end key, keymap settings
     */
    enum ARROW {
        LEFT = -68,
        RIGHT = -67,
        UP = -65,
        DOWN = -66,
        END = 101, // e
        ARROW_OTHER = 0
    };

    /**
     * Enum for menu keys, keymap settings
     */
    enum MENU {
        START_B = 115, // s
        START_M = 109, // m
        EXIT = 101, // e
        MENU_OTHER = 0
    };

    /**
     * Reading user input in linux systems
     * Credit to http://www.cplusplus.com/forum/articles/7312/#msg33734
     *
     * @return Key number if reading was successful, otherwise 0
     */
    int PressAnyKey() const;

    /**
     * Read key and convert it to ARROW enum
     * @return pressed ARROW key from enum
     */
    ARROW getArrow() const;

    /**
     * Read key and convert it to MENU enum
     * @return pressed MENU key from enum
     */
    MENU getMenu() const;

    /**
     * Print string to console
     * @param sequence String for printing
     */
    static void print(const std::string &sequence);

    /**
     * Print string to console, ending with endl (new line)
     * @param line String for printing
     */
    static void printLine(const std::string &line = "");

    /**
     * Clear console
     */
    static void clear();

private:
    /**
     * Variable for enabling or disabling debug mode in console
     */
    static const bool debug = false;

    /**
     * Method for printing pressed key value, for debugging
     * @param key pressed key int value
     */
    void printKey(int key) const;
};