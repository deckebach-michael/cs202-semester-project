#include "menu.h"

#include <iostream>

int Menu::displayStart() {
    int user_choice;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "1. Start program" << std::endl;
    std::cout << "2. Quit" << std::endl;
    std::cout << "Select a menu option: ";
    std::cin >> user_choice;

    return user_choice;
}

std::string Menu::getFileName() {
    std::string file_name;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Enter a filename: ";
    std::cin >> file_name;
    return file_name;
}

int Menu::displayProcesserMenu() {
    int processor_choice;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Audio Effect Options" << std::endl;
    std::cout << "1. Normalization" << std::endl;
    std::cout << "2. Echo" << std::endl;
    std::cout << "3. Gain Adjustment" << std::endl;
    std::cout << "Select the audio effect to apply: ";
    std::cin >> processor_choice;

    return processor_choice;

}

std::string Menu::getOutputName() {
    std::string output_name;

    std::cout << "-----------------------------------------" << std::endl;
    std:: cout << "Output file name (exclude .wav extension): ";
    std::cin >> output_name;
    
    return output_name;
}