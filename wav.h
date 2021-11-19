#ifndef SEMESTER_PROJECT
#define SEMESTER_PROJECT

#include "waveHeader.h"

class Wav {
public:
    void readFile(const std::string &fileName);
    void writeFile(const std::string &outFileName);
private:
    unsigned char* buffer = NULL;
    wav_header waveHeader;
public:
    virtual ~Wav();

public:
    unsigned char *getBuffer();
    int getBufferSize() const;
};


#endif 
