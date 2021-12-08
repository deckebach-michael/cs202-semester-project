/** @file limiter.h
* Is used to limit the aplitude of wav files 
*/
#ifndef LIMIT_H
#define LIMIT_H

#include <iostream>
#include "processor.h"

using namespace std;
/**
 * @brief limiter class is a class that can limit the amplitude of a given file
 *
 */
class Limiter: public Processor{

private:
	float limitVal = 0.8;

public:
	/**
	 * @brief allows you to limit the aplitude of a wav file
	 * @reutrn Char
	 * @reutrn int
	 */
	void limitFunc(unsigned char*, int);
	/**
	 * @brief Process Buffer creats a buffer that ajusts for the variation is processor speed
	 *
	 * @return char
	 * @reutrn int
	 */
	void processBuffer(unsigned char* buffer, int bufferSize);
};

#endif
