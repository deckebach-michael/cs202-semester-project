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
    std:: cout << "Output file name (include .wav): ";
    std::cin >> output_name;
    
    return output_name;
}

void Menu::shutdown() {
    std::cout << "... goodbye ..." << std::endl;
}

void Menu::invalidProcessorSelection() {
    std::cout << "Sorry, invalid processor option selected" << std::endl;
}

void Menu::displayWavStats(Wav const &wave) {
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "File: " << wave.getInputFile() << std::endl;
    std::cout << "Sample Rate: " << wave.getSampleRate() << std::endl;
    std::cout << "Bits Per Sample: " << wave.getBitDepth() << std::endl;
    std::cout << "Stereo or Mono: " << wave.getChannels() << std::endl; 
}

void Menu::displayWriteSuccess(std::string file) {
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << file + " written succesfully!" << std::endl;
}