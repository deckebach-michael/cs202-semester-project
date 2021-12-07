#ifndef NORMALIZATION_H
#define NORMALIZATION_H
#include "limiter.h"
#include <vector>
#include <cmath>

class Normalization{
public:
	static std::vector<float> process(const std::vector<float> &input);
};
#endif
