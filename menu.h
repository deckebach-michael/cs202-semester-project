/** @file menue.h
* echo used to alter the wav file to creat an echo.
*/
#ifndef MENU_H
#define MENU_H

#include <string>
#include "wav.h"

/**
 * @brief Abstract class used to organize all terminal UI functionality.
 * 
 */
class Menu {
public:

    /**
     * @brief Show the start menu, which prompts the user to either 
     * being (1) or quit (2). It returns the user's selection.
     * 
     * @return int 
     */
    static int displayStart();

    /**
     * @brief Outputs to the terminal a goodbye message that the program
     * is ending.
     * 
     */
    static void shutdown();

    /**
     * @brief Prompts the user for the name of a file, which it
     * returns to the calling function.
     * 
     * @return std::string 
     */
    static std::string getFileName();

    /**
     * @brief Displays the input file name, sample rate, bits per sample
     * and stereo or mono to the console.
     * 
     * @param wave The Wav object you want to display summary statistics for.
     */
    static void displayWavStats(Wav const &wave);

    /**
     * @brief Displays the processing options to the terminal, such as
     * normalization, echo, and gain adjustment.
     * 
     * @return int representing the user's selection.
     */
    static int displayProcesserMenu();

    /**
     * @brief Outputs an error message indicating an improper processor selection
     * was selected when called. Takes no parameters and outputs nothing.
     * 
     */
    static void invalidProcessorSelection();

    /**
     * @brief Prompts user via terminal for an output file name
     * 
     * @return std::string the name of the file to be output
     */
    static std::string getOutputName();

    /**
     * @brief Outputs a success message indicating that a file has been 
     * written. 
     * 
     * @param file the name of the file that has been successfully written.
     */
    static void displayWriteSuccess(std::string file);

    /**
     * @brief Gets a float between 0.0 and 2.0 from the user on the 
     * command line
     * 
     * @return float 
     */
    static float getFloat();
};

#endif // MENU_H
