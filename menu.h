#ifndef MENU_H
#define MENU_H

#include <string>
#include "wav.h"

class Menu {
public:
    static int displayStart();
    static void shutdown();

    static std::string getFileName();
    static void displayWavStats(Wav const &wave);

    static int displayProcesserMenu();
    static void invalidProcessorSelection();

    static std::string getOutputName();
    static void displayWriteSuccess(std::string file);
};

#endif // MENU_H
