#include <fstream>
#include <iostream>
#include "wav.h"



void Wav::readFile(const std::string &fileName) {
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&waveHeader, sizeof(wav_header));
        file.close();
    }
}


unsigned char *Wav::getBuffer(){
    return buffer;
}

void Wav::writeFile(const std::string &outFileName) {

    // outFileName.close();
}

Wav::~Wav() {
    if(buffer != NULL)
        delete[] buffer;
}

int Wav::getBufferSize() const {
    return waveHeader.data_bytes;
}

bool Wav::is_wav(std::string file_name) {
    if (file_name.length() >= 4) {
        return (0 == file_name.compare(file_name.length() - 4, 4, ".wav"));
    } else {
        return false;
    }
}

bool Wav::is_valid(std::string file_name) {
    
    std::ifstream fstrm(file_name);

    if (is_wav(file_name) && (!fstrm.fail())) {
        return true;
    } 
    else {
        return false;
    }
}

