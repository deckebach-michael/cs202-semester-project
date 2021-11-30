#ifndef SEMESTER_PROJECT
#define SEMESTER_PROJECT


#include <cstdint>
#include <cmath>

class Processor {
public:
    virtual void processBuffer(unsigned char* buffer, int bufferSize) = 0;
};


#endif
