#include <fstream>
#include <iostream>
#include <algorithm>

#include "wav.h"



int Wav::read(const std::string &file) {

    // Open a file pointer (fp) to read in the file
    std::ifstream fptr(file, std::ios::binary | std::ios::in);

    // Check to make sure the file opened correctly
    if (!fptr.is_open()) {
        std::cout << "Could not open the file" << std::endl;
        return 0;
    }

    // Read in header data
    fptr.read((char*) &header, sizeof(header));

    // File validity: check for RIFF header
    std::string riff_header(header.riff_header, 4);
    if (riff_header != "RIFF") {
        std::cout << "Not a RIFF file" << std::endl;
        return 0;
    }

    // File validity: check for WAVE header
    std::string wave_header(header.wave_header, 4);
    if (wave_header != "WAVE") {
        std::cout << "Not a WAVE file" << std::endl;
        return 0;
    }

    // Create channel vectors to hold wav data
    int samples = header.data_bytes / header.sample_alignment;
    for (int i = 0; i < header.num_channels; i++) {
        channels.emplace_back(samples);
    }

    // Read a chunk of data into a buffer, according to bit_depth
    switch (header.bit_depth) {
        case 8: // 8-bit files
            {
                // Read data into buffer as bytes
                unsigned char buffer[header.data_bytes];
                fptr.read((char*)buffer, header.data_bytes);

                // Convert each byte to a -1 to 1 float and copy to proper channel
                for (int i = 0; i < header.data_bytes; i++) {
                    channels[i % header.num_channels].setSample(
                        i / header.num_channels,
                        ((float)buffer[i] - (MAX_8BIT / 2)) / (MAX_8BIT / 2));
                }
            }
            break;
        case 16: // 16-bit files
            {
                // Read data into buffer as shorts
                short buffer[header.data_bytes / 2];
                fptr.read((char*)buffer, header.data_bytes);

                // Convert each short to a -1 to 1 float and copy to proper channel
                for (int i = 0; i < header.data_bytes / 2; i++) {
                    channels[i % header.num_channels].setSample(
                        i / header.num_channels,
                        ((float)buffer[i] / MAX_16BIT));
                }
            }
            break;
        default:
            std::cout << "Unsupported bit depth" << std::endl;
            return 0;
    }

    // Close the file
    fptr.close();
    return 1;
}

int Wav::write(const std::string &file) {

    // Open a file pointer for writing
    std::ofstream fptr(file + ".wav", std::ios::binary | std::ios::out);

    // Check to make sure the file opened correctly
    if (!fptr.is_open()) {
        std::cout << "Could not open the file for writing" << std::endl;
        return 0;
    }

    // Write the header
    fptr.write((char*) &header, sizeof(header));
    
    // Organize the data in a buffer, according to bit_depth and num_channels
    switch (header.bit_depth) {
        case 8: // 8-bit files
            {
                // Convert each byte back to unsigned chars
                unsigned char buffer[header.data_bytes];
                for (int i = 0; i < header.data_bytes; i++) {
                    float temp = channels[1 % header.num_channels].getSample(
                            i / header.num_channels);
                    temp = (temp * (MAX_8BIT / 2)) + (MAX_8BIT / 2);
                    buffer[i] = (unsigned char)temp;
                }
            }
            break;
        // case 16: // 16-bit files
        //     {
        //         // Read data into buffer as shorts
        //         short buffer[header.data_bytes / 2];
        //         fptr.read((char*)buffer, header.data_bytes);

        //         // Convert each short to a -1 to 1 float and copy to proper channel
        //         for (int i = 0; i < header.data_bytes / 2; i++) {
        //             channels[i % header.num_channels].setSample(
        //                 i / header.num_channels,
        //                 ((float)buffer[i] / MAX_16BIT));
        //         }
        //     }
        //     break;
        default:
            std::cout << "Unsupported bit depth" << std::endl;
            return 0;
    }

    // Close the file
    std::cout << file + ".wav written succesfully!" << std::endl;
    fptr.close();
    return 1;
}



int Wav::getSampleRate() const {
    return header.sample_rate;
}
int Wav::getBitDepth() const {
    return header.bit_depth;
}
std::string Wav::getChannels() const {
    switch (header.num_channels) {
        case 1:
            return "Mono";
            break;
        case 2:
            return "Stereo";
            break;
        default:
            return "Invalid";
    }
}