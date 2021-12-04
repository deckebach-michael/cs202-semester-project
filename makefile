WavModifier: main.cpp menu.cpp wav.cpp
	g++ -g -o WavModifier main.cpp menu.cpp wav.cpp

clean:
	rm *.o WavModifier