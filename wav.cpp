#include <fstream>
#include <iostream>
#include <algorithm>

#include "wav.h"



void Wav::readFile(const std::string &fileName) {
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&waveHeader, sizeof(wav_header));

        switch (this->waveHeader.sample_alignment) {
            case 1: // 8-bit
                {unsigned char buffer[waveHeader.data_bytes];
                file.read((char*)buffer, waveHeader.data_bytes);
                for (int i = 0; i < waveHeader.data_bytes / waveHeader.sample_alignment; i++) {
                    data.push_back(((float)buffer[i] - 127) / 127);
                }}
                break;

            case 2: // 16-bit
                {short buffer[waveHeader.data_bytes / waveHeader.sample_alignment];
                file.read((char*)buffer, waveHeader.data_bytes);
                for (int i = 0; i < waveHeader.data_bytes / waveHeader.sample_alignment; i++) {
                    data.push_back((float)buffer[i] / 32768);
                }}
                break;
        }

        for (int i = 0; i+1000 < waveHeader.data_bytes / waveHeader.sample_alignment; i += 1000) {
            std::cout << i << " | " << data[i] << std::endl;
        }

        float max = *std::max_element(data.begin(), data.end());
        float min = *std::min_element(data.begin(), data.end());
        std::cout << "MAX VALUE = " << max << std::endl;
        std::cout << "MIN VALUE = " << min << std::endl;

        file.close();
    }
}

// unsigned char *Wav::getBuffer(){
//     return buffer;
// }

void Wav::writeFile(const std::string &outFileName) {

    // outFileName.close();
}

Wav::~Wav() {
}

int Wav::getBufferSize() const {
    return waveHeader.data_bytes;
}

bool Wav::isWav(std::string file_name) {
    if (file_name.length() >= 4) {
        return (0 == file_name.compare(file_name.length() - 4, 4, ".wav"));
    } else {
        return false;
    }
}

bool Wav::isValid(std::string file_name) {
    
    std::ifstream fstrm(file_name);

    if (isWav(file_name) && (!fstrm.fail())) {
        return true;
    } 
    else {
        return false;
    }
}


int Wav::getSampleRate() const {
    return waveHeader.sample_rate;
}
int Wav::getBitDepth() const {
    return waveHeader.bit_depth;
}
int Wav::getNumChannels() const {
    return waveHeader.num_channels;
}