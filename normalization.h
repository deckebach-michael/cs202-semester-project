	/** @file normalization.h
	* Sets Values to 1 and corrects amplitude relative to the file
	*/
#ifndef NORMALIZATION_H
#define NORMALIZATION_H
#include "limiter.h"
#include <vector>
#include <cmath>
/**
 * @brief normalization class used to return the program to its normal state.
 *
 */
class Normalization{
public:
	/**
	 * @brief process keeps the values from going out of bounds.
	 * @reutrn float
	 *
	 */
	static std::vector<float> process(const std::vector<float> &input);
};
#endif
