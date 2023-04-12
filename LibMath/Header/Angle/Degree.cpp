#include "Degree.h"

LibMath::Degree::Degree()
{
	m_value = 0;
}

LibMath::Degree::Degree(float value)
{
	m_value = value;
}

LibMath::Degree::Degree(Degree const& degree)
{
	m_value = degree.m_value;
}

LibMath::Degree::~Degree()
{

}

LibMath::Degree& LibMath::Degree::operator=(Degree const& degree)
{
	m_value = degree.m_value;
	return *this;
}

LibMath::Degree& LibMath::Degree::operator+=(Degree degree)
{
	m_value += degree.m_value;
	if (m_value > 180)
		m_value -= 360;
	if (m_value < -180)
		m_value += 360;
	return *this;
}

LibMath::Degree& LibMath::Degree::operator-=(Degree degree)
{
	m_value -= degree.m_value;
	if (m_value > 180)
		m_value -= 360;
	if (m_value < -180)
		m_value += 360;
	return *this;
}

LibMath::Degree& LibMath::Degree::operator*=(float value)
{
	m_value *= value;
	if (m_value > 180)
		m_value -= 360;
	if (m_value < -180)
		m_value += 360;
	return *this;
}

LibMath::Degree& LibMath::Degree::operator/=(float value)
{
	m_value /= value;
	if (m_value > 180)
		m_value -= 360;
	if (m_value < -180)
		m_value += 360;
	return *this;
}

float LibMath::Degree::raw() const
{
	return m_value;
}

bool LibMath::operator==(Degree Ldegree, Degree Rdegree)
{
	if (Ldegree.raw() == Rdegree.raw())
		return true;
	else
		return false;
}
//
//bool LibMath::operator==(Degree Ldegree, Radian const& Rradian)
//{
//	/*if (Ldegree.raw() == Rradian.raw())
//		return true;
//	else
//		return false;*/
//}

LibMath::Degree LibMath::operator-(Degree degree)
{
	Degree newDegree(-degree.raw());
	return newDegree;
}

LibMath::Degree LibMath::operator+(Degree firtDegree, Degree secondDegree)
{
	Degree newDegree(firtDegree.raw() + secondDegree.raw());
	return newDegree;
}

LibMath::Degree LibMath::operator-(Degree firtDegree, Degree secondDegree)
{
	Degree newDegree(firtDegree.raw() - secondDegree.raw());
	return newDegree;
}

LibMath::Degree LibMath::operator*(Degree degree, float value)
{
	Degree newDegree(degree.raw() * value);
	return newDegree;
}

LibMath::Degree LibMath::operator/(Degree degree, float value)
{
	Degree newDegree(degree.raw() / value);
	return newDegree;
}
