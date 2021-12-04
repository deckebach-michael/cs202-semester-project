#ifndef SEMESTER_PROJECT
#define SEMESTER_PROJECT

#include <string>
#include <vector>

#include "waveheader.h"

class Wav {
// public:  // NEED TO DELETE
//     unsigned char* buffer = nullptr;
//     short* buffer16 = nullptr;

    wav_header waveHeader;
    std::vector<float> data;
public:
    void readFile(const std::string &fileName);
    void writeFile(const std::string &outFileName);
    virtual ~Wav();

    // unsigned char *getBuffer();
    int getBufferSize() const;

    static bool isWav(std::string file_name);
    static bool isValid(std::string file_name);

    int getSampleRate() const;
    int getBitDepth() const;
    int getNumChannels() const;

};


#endif 
