#pragma once

#include <string>

class Console {
public:
    enum ARROW {
        LEFT = -68,
        RIGHT = -67,
        UP = -65,
        DOWN = -66,
        END = 101, // e
        ARROW_OTHER = 0
    };
    enum MENU {
        START = 115, // s
        EXIT = 101, // e
        MENU_OTHER = 0
    };

    int PressAnyKey() const;

    ARROW getArrow() const;

    MENU getMenu() const;

    static void print(const std::string &sequence);

    static void printLine(const std::string &line = "");

    static void clear();

private:
    static const bool debug = false;

    void printKey(int key) const;
};