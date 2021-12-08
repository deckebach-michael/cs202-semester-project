/** @file processor.h
* File contains definition for processor interface
*/
#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "wav.h"

/**
 * @brief Interface for wav object modification
 * 
 */
class Processor {
public:
  virtual void interface() = 0;
  static void process(Wav &wave);
};


#endif
