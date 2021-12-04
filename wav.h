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
 * 
 * The read function takes a file address and reads all 
 * data into the Wav object. Some error checking is included.
 * Data will automatically be converted to floating point values in
 * the range of -1 to 1. Data is also automatically parsed into the 
 * correct channels. 8-bit and 16-bit depth Wav files are supported.
 * 
 * The write function does the inverse of the read function.
 * 
 */

class Wav {
    std::string inputFile;
    wav_header header;
    std::vector<Channel> channels;
public:
    int read(const std::string &file);
    int write(const std::string &file);

    virtual ~Wav() = default;

    int getSampleRate() const;
    int getBitDepth() const;
    std::string getChannels() const;
    std::string getInputFile() const;
};

#endif 