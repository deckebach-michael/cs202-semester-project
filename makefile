WavModifier: main.cpp menu.cpp wav.cpp normalization.cpp gain.cpp
	g++ -o WavModifier main.cpp menu.cpp wav.cpp normalization.cpp gain.cpp

clean:
	rm *.o WavModifier