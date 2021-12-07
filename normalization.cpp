#include "normalization.h"

std::vector<float> Normalization::process(const std::vector<float> &input){
	float max = std::abs(input[0]);
	for(int i = 0; i < input.size(); i++)
	{
		float value = std::abs(input[i]);
		if(value > max){
			max = value;
		}
	}
	float scalar = 0.0;
	if(max != 0){
		scalar = 1/max;
	}
	return limiter::process(input,scalar);
}

