#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>

  using namespace std; 
  typedef struct  WAV_HEADER
    {
      //Dr. Lancasters header if you need to know what stuff does
        ushort          riff_header[4];  
        unsigned int        wav_size;  
        ushort              wave_header[4];   
        ushort              fmt_header[4];   
        unsigned int        fmt_chunk_size;  
        ushort              audio_format;  
        ushort        num_channels;   
        unsigned int        sample_rate; 
        unsigned int        byte_rate;   
        ushort        sample_alignment;   
        ushort        bit_depth; 
        ushort         data_header[4];
        unsigned int        data_bytes;
    } wav_hdr;
    int getFileSize(FILE* iFile)
      {
          int fileS = 0;
          fseek(iFile, 0, SEEK_END);
      
          fileS = ftell(iFile);
      
          fseek(iFile, 0, SEEK_SET);
          return fileS;
      }
    int main(int argc, char* argv[])
  {
        wav_hdr wavH;
        int headerS = sizeof(wav_hdr), fileL = 0;
        const char* fileP;
        string input;
      if (argc <= 1)
      {
          cout << "Input wave file name: ";
          cin >> input;
          cin.get();
          fileP = input.c_str();
      }
    else
      {
          fileP = argv[1];
          cout << "Input wave file name: " << fileP << endl;
      }

      FILE* wavF = fopen(fileP, "r");
    if (wavF == nullptr)
      {
          fprintf(stderr, "Unable to open wave file: %s\n", fileP);
          return 1;
      }
      //Read header
        size_t bytesR = fread(&wavH, 1, headerS, wavF);
        
        cout << "Header Read " << bytesR << " bytes." << endl;
        
    if (bytesR > 0)
      {
          //Read data
          ushort bytesPerSample = wavH.bit_depth / 8;     

          unsigned int numSamples = wavH.wav_size / bytesPerSample;

        static const ushort BUFFER_SIZE = 4096;

          ushort* buffer = new ushort[BUFFER_SIZE];

        while ((bytesR = fread(buffer, sizeof buffer[0], BUFFER_SIZE / (sizeof buffer[0]), wavF)) > 0)
          {
              /** waveheader HERE **/
              cout << "Read " << bytesR << " bytes." << endl;
          }
          
        delete [] buffer;

          buffer = nullptr;

          fileL = getFileSize(wavF);

          cout << "File is                    :" << fileL << " bytes." << endl;

          cout << "riff_header header                :" << wavH.riff_header[0] << wavH.riff_header[1] << wavH.riff_header[2] << wavH.riff_header[3] << endl;

          cout << "wave_header header                :" << wavH.wave_header[0] << wavH.wave_header[1] << wavH.wave_header[2] << wavH.wave_header[3] << endl;

          cout << "FMT                        :" << wavH.fmt_header[0] << wavH.fmt_header[1] << wavH.fmt_header[2] << wavH.fmt_header[3] << endl;

          cout << "Data size                  :" << wavH.wav_size << endl;

          cout << "Sampling Rate              :" << wavH.sample_rate << endl;

          cout << "Number of bits used        :" << wavH.bit_depth << endl;

          cout << "Number of channels         :" << wavH.num_channels << endl;

          cout << "Number of bytes per second :" << wavH.byte_rate << endl;

          cout << "Data length                :" << wavH.data_bytes << endl;

          cout << "Audio Format               :" << wavH.audio_format << endl;

          cout << "Block align                :" << wavH.sample_alignment << endl;

          cout << "Data string                :" << wavH.data_header[0] << wavH.data_header[1] << wavH.data_header[2] << wavH.data_header[3] << endl;
      }

      fclose(wavF);
      
      return 0;
  }
