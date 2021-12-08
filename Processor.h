/** @file processor.h
* echo used to alter the wav file to creat an echo.
*/
#ifndef SEMESTER_PROJECT
#define SEMESTER_PROJECT


#include <cstdint>
#include <cmath>
/**
 * @brief Processor class interface used by linear sub-classes.
 *
 *@return char
 *@return int
 */
class Processor {
public:
  /**
	 * @brief Process Buffer creats a buffer that ajusts for the variation in processor speed. 
	 *
   *@return char
   *@return int
	 */
    virtual void processBuffer(unsigned char* buffer, int bufferSize) = 0;
};


#endif
