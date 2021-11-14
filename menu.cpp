#include "menu.h"

#include <iostream>


void Menu::display() {
    std::cout << "Please select an option:" << std::endl;
    std::cout << "1. Modify WAV file" << std::endl;
    std::cout << "2. Exit" << std::endl;
};