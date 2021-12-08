/** @file echo.h
* echo used to alter the wav file to creat an echo.
*/
#ifndef ECHO_H
#define ECHO_H


#include <iostream>
#include "processor.h"
/**
 * @brief The echo class is used to alter WAV file data in memory to creat an echo.
 *
 *
 */
class Echo:public Processor{
	
private:

	int delay;

public:

	Echo();
	/**
	 * @brief Creats an echo in the wav file.
	 * @reutrn char
	 * @reutrn int
	 */
	Echo(int);

	void createEcho(unsigned char*, int);	
	/**
	 * @brief Process Buffer creats a buffer that ajusts for the variation is processor speed
	 *
	 * @reutrn char
	 * @return int
	 */
	void processBuffer(unsigned char* buffer, int bufferSize);
	
};

	

#endif
