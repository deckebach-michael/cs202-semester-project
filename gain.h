/** @file gain.h
* Contains virtual gain class, used to adjust amplitude of file
*/

#ifndef GAIN_H
#define GAIN_H

#include "processor.h"
#include "wav.h"

/**
 * @brief Gain adjustment class modifies samples by a scaling factor
 * that raises or lowers the overall amplitude of the wave file
 *
 */
class Gain : public Processor {
public:
	static void process(Wav &wave, float factor);    
};

#endif
