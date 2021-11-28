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

        // Get source file and check for valid wav format
        file_name = Menu::getFileName();
        if (!Wav::is_valid(file_name)) {
            continue;
        }

        // TODO: Read file metadata
        // TODO: Display file metadata

        // Present processer menu
        processor_choice = Menu::displayProcesserMenu();

        // Get output file name
        output_name = Menu::getOutputName();

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
        }

        // TODO: Save file to output_name
    }

    return 0;
};