#include "Console.h"

#include <iostream>

#include <cstdio>
#include <unistd.h>
#include <termios.h>

#include <memory>
#include <cstring>

/*
 * Reading user input in linux systems
 * Credit to http://www.cplusplus.com/forum/articles/7312/#msg33734
 */
int Console::PressAnyKey() const {
#define MAGIC_MAX_CHARS 18
    struct termios initial_settings;
    struct termios settings;
    unsigned char keycodes[MAGIC_MAX_CHARS];
    int count;

    tcgetattr(STDIN_FILENO, &initial_settings);
    settings = initial_settings;

    // Set the console mode to no-echo, raw input.
    // The exact meaning of all this jazz will be discussed later.
    settings.c_cc[VTIME] = 0;
    settings.c_cc[VMIN] = 0; //MAGIC_MAX_CHARS
    settings.c_iflag &= ~(IXOFF);
    settings.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &settings);

    //printf("%s", prompt ? prompt : "Press a key to continue...");
    //read 0 ? stdin
    count = read(STDIN_FILENO, (void *) keycodes, MAGIC_MAX_CHARS);

    tcsetattr(STDIN_FILENO, TCSANOW, &initial_settings);

    if (count == 0) {
        return 0;
    } else if (count == 1) {
        return keycodes[0];
    } else {
        return -(int) (keycodes[count - 1]);
    }
}

void Console::printKey(int key) const {
    if (debug)
        std::cout << "Pressed key: " << key << std::endl;
}

Console::ARROW Console::getArrow() const {
    int key = PressAnyKey();
    switch (key) {
        case (LEFT):
            printKey(key);
            return LEFT;
        case (RIGHT):
            printKey(key);
            return RIGHT;
        case (UP):
            printKey(key);
            return UP;
        case (DOWN):
            printKey(key);
            return DOWN;
        case (END):
            printKey(key);
            return END;
        default:
            printKey(key);
            return ARROW_OTHER;
    }
}

Console::MENU Console::getMenu() const {
    int key = PressAnyKey();
    switch (key) {
        case (START_B):
            printKey(key);
            return START_B;
        case (START_M):
            printKey(key);
            return START_M;
        case (EXIT):
            printKey(key);
            return EXIT;
        default:
            printKey(key);
            return MENU_OTHER;
    }
}

void Console::print(const std::string &sequence) {
    std::cout << sequence;
}

void Console::printLine(const std::string &line) {
    std::cout << line << std::endl;
}

void Console::clear() {
    std::cout << std::flush;
    //system("clear");
    std::cout << "\033[2J\033[1;1H";
}
