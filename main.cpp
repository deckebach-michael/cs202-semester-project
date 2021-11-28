#include "menu.h"

#include <iostream>
#include <string>
#include <fstream>

bool is_wav(std::string file_name) {
    if (file_name.length() >= 4) {
        return (0 == file_name.compare(file_name.length() - 4, 4, ".wav"));
    } else {
        return false;
    }
}

bool is_valid(std::string file_name) {
    
    std::ifstream fstrm(file_name);

    if (is_wav(file_name) && (!fstrm.fail())) {
        return true;
    } 
    else {
        return false;
    }
}


int main(void) {

    int user_choice;
    int processor_choice;
    std::string file_name;
    std::string output_name;

    while (!is_valid(file_name)) {

        std::cout << "1. Start program" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cin >> user_choice;

        if (user_choice == 2) {
            std::cout << "... goodbye ..." << std::endl;
            return 1;
        }

        std::cout << "Enter a filename: ";
        std::cin >> file_name;
    }

    // TODO: Read file metadata
    // TODO: Display file metadata

    // Present processer menu
    std::cout << "Please select the audio effect to apply to your file:" << std::endl;
    std::cout << "1. Normalization" << std::endl;
    std::cout << "2. Echo" << std::endl;
    std::cout << "3. Gain Adjustment" << std::endl;
    std::cin >> processor_choice;

    // Get output file name
    std:: cout << "Output file name: ";
    std::cin >> output_name;

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
    // TODO: Go back to Start



    // Menu menu;
    // menu.display();

    return 0;
};