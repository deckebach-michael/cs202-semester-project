#include "gain.h"

void Gain::process(Wav &wave, float factor) {
    
    int numChannels = wave.getNumChannels();

    for (int i = 0; i < numChannels; i++) {
        
        Channel chan = wave.getChannel(i);
        int chanLen = chan.length();

        for (int j = 0; j < chanLen; j++) {

            float temp = chan.getSample(j) * factor;
            chan.setSample(j, temp);
        }
    }
}
