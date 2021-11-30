#include "echo.h"
#include <iostream>

Echo::Echo(){
	delay = 0;
}

Echo::Echo(int newDelay){
	delay = newDelay;
}

void Echo::createEcho(unsigned char* buffer, int bufferSize){

	for(int i = delay; i < bufferSize; i++){
		if((buffer[i] + buffer[i-delay]) > 255){
			buffer[i] = 255;
		}
		else{
			buffer[i] = buffer[i] + buffer[i-delay];
		}
}
}

void Echo::processBuffer(unsigned char* buffer, int bufferSize){
	createEcho(buffer, bufferSize);
}

