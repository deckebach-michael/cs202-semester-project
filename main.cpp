#include "menu.h"
#include "wav.h"

#include <iostream>
#include <string>
#include <fstream>


int main(void) {

    int user_choice;
    int processor_choice;
    std::string file_name;
    std::string output_name;

    while (true) {

        // Exit program if user enters 2
        user_choice = Menu::displayStart();
        if (user_choice == 2) {
            std::cout << "... goodbye ..." << std::endl;
            return 1;
        }

        // Get source file from user
        file_name = Menu::getFileName();

        Wav myFile;
        int readSuccess = myFile.read(file_name);
        if (!readSuccess) {
            continue;
        }

        // Display file metadata
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << "File: " << file_name << std::endl;
        std::cout << "Sample Rate: " << myFile.getSampleRate() << std::endl;
        std::cout << "Bits Per Sample: " << myFile.getBitDepth() << std::endl;
        std::cout << "Stereo or Mono: " << myFile.getChannels() << std::endl; 

        // Present processer menu
        processor_choice = Menu::displayProcesserMenu();
        switch(processor_choice) {
            case 1:
                // TODO: normalization function
                break;
            case 2:
                // TODO: echo function
                break;
            case 3:
                // TODO: gain adjustment function
                break;
            default:
                std::cout << "Sorry, invalid processor option selected" << std::endl;
                continue;
        }

        // Get output file name
        output_name = Menu::getOutputName();
        myFile.write(output_name);
    }

    return 0;
};