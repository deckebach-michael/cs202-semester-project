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
    Channel(int numSamples) {
        data = std::vector<float>(numSamples);
    }

    float getSample(int index) const {
        return data[index];
    }

    void setSample(int index, float value) {
        data[index] = value;
    }
};


#endif 
