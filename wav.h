#ifndef SEMESTER_PROJECT
#define SEMESTER_PROJECT

#include <string>
#include <vector>

#include "waveheader.h"
#include "channel.h"

const int MAX_8BIT = 255;
const int MAX_16BIT = 32768;

class Wav {
    wav_header header;
    std::vector<Channel> channels;
public:
    void read(const std::string &file);
    // void write(const std::string &file);

    virtual ~Wav() = default;

    int getSampleRate() const;
    int getBitDepth() const;
    std::string getChannels() const;

};


#endif 
