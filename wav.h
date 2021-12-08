/** @file wav.h
* Used to read and write wav files.
*/
#ifndef WAV_H
#define WAV_H

#include <string>
#include <vector>

#include "waveheader.h"
#include "channel.h"

const int MAX_8BIT = 255;
const int MAX_16BIT = 32768;

/**
 * @brief The main class used to represent WAV file data in memory.
 * The vector of Channels is used to capture and organize the data for
 * each channel in a WAV file (e.g., stereo = L & R). 
 */

class Wav {
    std::string inputFile;
    wav_header header;
    std::vector<Channel> channels;
public:

    /**
     * @brief takes a file address and reads all
     * data into the Wav object. Some error checking is included.
     * Data will automatically be converted to floating point values
     * in the range of -1 to 1. Data is also automatically parsed into
     * the correct channels. 8-bit and 16-bit depth wav files are supported.
     * 
     * @param file the name of the Wav file to be read into memory
     * @return int returns 1 if successful, else returns 0
     */
    int read(const std::string &file);

    /**
     * @brief takes a file name and writes data from 
     * the Wav object into that file. Data is converted from floating point
     * back into bytes in proper Wav format. 8-bit and 16-bit supported.
     * 
     * @param file the name of the Wav file to be written
     * @return int returns 1 if successful, else returns 0
     */
    int write(const std::string &file);

    /**
     * @brief Destroy the Wav object
     * 
     */
    virtual ~Wav() = default;

    /**
     * @brief Get the Sample Rate of the Wav object
     * 
     * @return int
     */
    int getSampleRate() const;

    /**
     * @brief Get the Bit Depth of the Wav object
     * 
     * @return int 
     */
    int getBitDepth() const;

    /**
     * @brief Get the Channels of the Wav object.
     * Returns "Mono" if there is 1 channel, and 
     * "Stereo" if there are 2 channels. More than 2
     * channels is not supported.
     * 
     * @return std::string 
     */
    std::string getChannels() const;

    /**
     * @brief Get the Input File name of the Wav object.
     * 
     * @return std::string 
     */
    std::string getInputFile() const;

    int getNumChannels() const;

    Channel& getChannel(int index);

};

#endif 
