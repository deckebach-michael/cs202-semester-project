/** @file normalization.h
* Sets Values to 1 and corrects amplitude relative to the file
*/

#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include "processor.h"
#include "wav.h"

/**
 * @brief normalization class used to scale the wav data to the
 * maximum possible value. This maximizes the amplitude of the 
 * final waveform.
 *
 */
class Normalization : public Processor {
public:
	static void process(Wav &wave);
};

#endif
