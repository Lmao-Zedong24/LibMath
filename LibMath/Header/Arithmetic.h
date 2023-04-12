#ifndef __LIBMATH__ARITHMETIC_H__
#define __LIBMATH__ARITHMETIC_H__

namespace LibMath
{
	float ceiling(float);				// Return lowest integer value higher or equal to parameter
	float clamp(float, float, float);	// Return parameter limited by the given range
	float floor(float);					// Return highest integer value lower or equal to parameter
	float squareRoot(float);			// Return square root of parameter
	float wrap(float, float, float);	// Return parameter as value inside the given range
	float power(float,int);
	float normalize(float);
}

#endif // !__LIBMATH__ARITHMETIC_H__
