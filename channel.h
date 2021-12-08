/** @file channel.h
* echo used to alter the wav file to creat an echo.
*/
#ifndef CHANNEL_H
#define CHANNEL_H

#include <vector>


/**
 * @brief A channel is just a simple class consisting of one vector of
 * floating point values used to represent the underlying data for one WAV
 * file channel.
 */

class Channel {
    
    std::vector<float> data;

public:

    /**
     * @brief Construct a new Channel object
     * 
     * @param numSamples An integer representing the number of samples 
     * in the channel.
     */
    Channel(int numSamples) {
        data = std::vector<float>(numSamples);
    }

    /**
     * @brief Return a sample value from the Channel object
     * 
     * @param index The location of the value you want to get
     * @return float 
     */
    float getSample(int index) const {
        return data[index];
    }

    /**
     * @brief Set a sample value in the Channel object
     * 
     * @param index The location of the value you want to set
     * @param value Floating point value to be stored at the index
     */
    void setSample(int index, float value) {
        data[index] = value;
    }

    int length() {
        return data.size();
    }
};


#endif 
