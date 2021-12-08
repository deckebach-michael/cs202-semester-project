#include <iostream>
#include <string>
#include <fstream>

#include "menu.h"
#include "wav.h"
#include "normalization.h"
#include "gain.h"


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
                Normalization::process(wave);
                break;
            case 2:
                // TODO: echo function
                std::cout << "Sorry:  functionality still under construction. Check back later!" << std::endl;
                break;
            case 3:
                {
                float factor = Menu::getFloat();
                Gain::process(wave, factor);
                }
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