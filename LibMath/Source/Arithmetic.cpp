#include "../Header/Arithmetic.h"
#include <cmath>

float LibMath::clamp(float value, float min, float max)
{ 
	if (value < min)
		value = min;
	if (value > max)
		value = max;

	return value;
}

float LibMath::squareRoot(float value)//babylonian
{
	/*if (value < 0)
		throw;

	float lastResult = value / 2;

	while (lastResult * lastResult != value)
		lastResult = (lastResult + value / lastResult) / 2;

	return lastResult;*/
	return sqrt(value);
}

float LibMath::power(float value, int exponent)
{
	float baseValue = value;

	for (int i = 1; i < exponent; i++)
		value *= baseValue;

	return value;
}

float LibMath::normalize(float value)
{
	if (value < 0)
		value *= -1;
	return value;
}
