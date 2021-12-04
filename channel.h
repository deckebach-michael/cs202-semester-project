#ifndef CHANNEL_H
#define CHANNEL_H

#include <vector>



class Channel {
public: // TEMPORARY
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
