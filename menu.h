#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
public:
    static int displayStart();
    static std::string getFileName();
    static int displayProcesserMenu();
    static std::string getOutputName();
};

#endif // MENU_H