#ifndef __LIBMATH__TRIGONOMETRY_H__
#define __LIBMATH__TRIGONOMETRY_H__

#include "Angle/Radian.h"

namespace LibMath
{
	extern float const g_pi;	 // useful constant pi -> 3.141592...

	float	sin(Radian);		// float result = sin(Radian{0.5});		// 0.479426
	float	cos(Radian);		// float result = sin(Degree{45});		// 0.707107			// this make use implicit conversion
	float	tan(Radian);		// float result = sin(0.5_rad);			// 0.479426			// this make use user defined litteral from bellow
	Radian	asin(float);		// Radian angle = asin(0.479426);		// Radian{0.500001}
	Radian	acos(float);		// Degree angle = acos(0.707107);		// Degree{44.99998}	// this make use implicit conversion
	Radian	atan(float);		// Radian angle = atan(0.546302);		// Radian{0.500000}
	Radian	atan(float, float); // Radian angle = atan(1, -2);			// Radian{2.677945}
}

#endif // !__LIBMATH__TRIGONOMETRY_H__
