#include "../Header/Trigonometry.h"

#include <cmath>

float LibMath::sin(Radian angle)
{
	return std::sin(angle.raw());
}

float LibMath::cos(Radian angle)
{
	return std::cos(angle.raw());
}

float LibMath::tan(Radian angle)
{
	return std::tan(angle.raw());
}

LibMath::Radian LibMath::asin(float value)
{
	Radian angle(std::asin(value));
	return angle;
}

LibMath::Radian LibMath::acos(float value)
{
	Radian angle(std::asin(value));
	return angle;
}

LibMath::Radian LibMath::atan(float value)
{
	Radian angle(std::asin(value));
	return angle;
}

//LibMath::Radian LibMath::atan(float, float)
//{
//	Radian angle(std::atan());
//	return angle;;
//}
