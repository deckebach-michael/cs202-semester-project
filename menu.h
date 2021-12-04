#ifndef MENU_H
#define MENU_H

#include <string>
#include "wav.h"

class Menu {
public:
    static int displayStart();
    static std::string getFileName();
    static int displayProcesserMenu();
    static std::string getOutputName();
    static void shutdown();
    static void invalidProcessorSelection();
    static void displayWavStats(Wav const &wave);
    static void displayWriteSuccess(std::string file);
};

#endif // MENU_H