#include "normalization.h"

void Normalization::process(Wav &wave) {

	float max = 0;
	float scalar = 0.0;
	int numChannels = wave.getNumChannels();

	for (int i = 0; i < numChannels; i++) {
		
		Channel chan = wave.getChannel(i);
		int chanLen = chan.length();

		for (int j = 0; j < chanLen; j++) {

			float temp = std::abs(chan.getSample(j));
			if (temp > max) {
				max = temp;
			}
		}
	}

	if(max != 0){
		scalar = 1 / max;
	}

	for (int i = 0; i < numChannels; i++) {

		Channel chan = wave.getChannel(i);
		int chanLen = chan.length();

		for (int j = 0; j < chanLen; j++) {
			float temp = chan.getSample(j) * scalar;
			chan.setSample(j, temp);
		}
	}
}

