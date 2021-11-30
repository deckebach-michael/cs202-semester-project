#ifndef ECHO_H
#define ECHO_H


#include <iostream>
#include "Processor.h"

class Echo:public Processor{
	
private:

	int delay;

public:

	Echo();

	Echo(int);

	void createEcho(unsigned char*, int);	

	void processBuffer(unsigned char* buffer, int bufferSize);
	
};

	

#endif
