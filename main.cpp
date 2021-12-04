#include "menu.h"
#include "wav.h"

#include <iostream>
#include <string>
#include <fstream>


int main(void) {

    while (true) {

        int user_choice;
        int processor_choice;
        std::string file_name;
        std::string output_name;
        Wav wave;

        // Exit program if user enters 2
        user_choice = Menu::displayStart();
        if (user_choice == 2) {
            Menu::shutdown();
            return 1;
        }
        else if (user_choice != 1) {
            continue;
        }

        // Get source file from user
        file_name = Menu::getFileName();

        // Read from the disc to the Wav object
        // Start the menu over if the read does not succeed
        int readSuccess = wave.read(file_name);
        if (!readSuccess) {
            continue;
        }

        // Display file metadata
        Menu::displayWavStats(wave);

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
                Menu::invalidProcessorSelection();
                continue;
        }

        // Get output file name
        output_name = Menu::getOutputName();
        if (wave.write(output_name)) {
            Menu::displayWriteSuccess(output_name);
        }
    }

    return 0;
};