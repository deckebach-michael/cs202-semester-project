#ifndef SEMESTER_PROJECT
#define SEMESTER_PROJECT

#include <string>

#include "waveheader.h"

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

    static bool is_wav(std::string file_name);
    static bool is_valid(std::string file_name);

};


#endif 
