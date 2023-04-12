#include "Vector2.h"

#include <math.h>
#include "Arithmetic.h"
#include <string>
#include <sstream>

LibMath::Vector2::Vector2(float value)
{
	m_x = value;
	m_y = value;
}

LibMath::Vector2::Vector2(float valueX, float valueY)
{
	m_x = valueX;
	m_y = valueY;
}

LibMath::Vector2::Vector2(Vector2 const& Vector2)
{
	m_x = Vector2.m_x;
	m_y = Vector2.m_y;
}

LibMath::Vector2::~Vector2()
{

}

LibMath::Vector2 LibMath::Vector2::zero()
{
	Vector2 newVector(0, 0);
	return newVector;
}

LibMath::Vector2 LibMath::Vector2::one()
{
	Vector2 newVector(1, 1);
	return newVector;
}

LibMath::Vector2 LibMath::Vector2::up()
{
	Vector2 newVector(0, 1);
	return newVector;
}

LibMath::Vector2 LibMath::Vector2::down()
{
	Vector2 newVector(0, -1);
	return newVector;
}

LibMath::Vector2 LibMath::Vector2::left()
{
	Vector2 newVector(-1, 0);
	return newVector;
}

LibMath::Vector2 LibMath::Vector2::right()
{
	Vector2 newVector(1, 0);
	return newVector;
}

LibMath::Vector2& LibMath::Vector2::operator=(Vector2 const& vector)
{
	m_x = vector.m_x;
	m_y = vector.m_y;

	return *this;
}

float& LibMath::Vector2::operator[](int index)
{
	switch (index)
	{
	case 0:
		return m_x;
		break;
	case 1:
		return m_y;
		break;
	default:
		throw;
		break;
	}
}

float LibMath::Vector2::operator[](int index) const
{
	switch (index)
	{
	case 0:
		return m_x;
		break;
	case 1:
		return m_y;
		break;
	default:
		throw;
		break;
	}
}

LibMath::Vector2& LibMath::Vector2::operator+=(Vector2 const& vector)
{
	m_x += vector.m_x;
	m_y += vector.m_y;

	return *this;
}

LibMath::Vector2& LibMath::Vector2::operator-=(Vector2 const& vector)
{
	m_x -= vector.m_x;
	m_y -= vector.m_y;

	return *this;
}

LibMath::Vector2& LibMath::Vector2::operator*=(Vector2 const& vector)
{
	m_x *= vector.m_x;
	m_y *= vector.m_y;

	return *this;
}

LibMath::Vector2& LibMath::Vector2::operator/=(Vector2 const& vector)
{
	m_x /= vector.m_x;
	m_y /= vector.m_y;

	return *this;
}

LibMath::Radian LibMath::Vector2::angleFrom(Vector2 const& vector) const
{
	Radian angle(acos(this->dot(vector) / (magnitude() * vector.magnitude())));

	return angle;
}

float LibMath::Vector2::distanceFrom(Vector2 const& vector) const
{
	return squareRoot((m_x - vector.m_x) * (m_x - vector.m_x) + (m_y - vector.m_y) * (m_y - vector.m_y));
}

float LibMath::Vector2::distanceSquaredFrom(Vector2 const& vector) const
{
	return (m_x - vector.m_x) * (m_x - vector.m_x) + (m_y - vector.m_y) * (m_y - vector.m_y);
}

//float LibMath::Vector3::distance2DFrom(Vector3 const& vector) const
//{
//	return 0.0f;
//}
//
//float LibMath::Vector3::distance2DSquaredFrom(Vector3 const& vector) const
//{
//	return 0.0f;
//}

float LibMath::Vector2::dot(Vector2 const& vector) const
{
	float dotProduct;

	dotProduct = m_x * vector.m_x + m_y * vector.m_y;

	return dotProduct;
}

bool LibMath::Vector2::isLongerThan(Vector2 const& vector) const
{
	if (magnitudeSquared() > vector.magnitudeSquared())
		return true;
	else
		return false;
}

bool LibMath::Vector2::isShorterThan(Vector2 const& vector) const
{
	if (magnitudeSquared() < vector.magnitudeSquared())
		return true;
	else
		return false;
}

bool LibMath::Vector2::isUnitVector() const
{
	if (magnitudeSquared() == 1.0f)
		return true;
	else
		return false;
}

float LibMath::Vector2::magnitude() const
{
	return squareRoot(m_x * m_x + m_y * m_y);
}

float LibMath::Vector2::magnitudeSquared() const
{
	return m_x * m_x + m_y * m_y;
}

void LibMath::Vector2::normalize()
{
	m_x /= magnitude();
	m_y /= magnitude();
}

void LibMath::Vector2::rotate(Radian, Radian, Radian)
{

}

void LibMath::Vector2::rotate(Radian, Vector2 const&)
{

}

void LibMath::Vector2::scale(Vector2 const& vector)
{
	m_x += vector.m_x;
	m_y += vector.m_y;
}

std::string LibMath::Vector2::string() const
{
	std::ostringstream oss;
	oss << "( " << m_x << ", " << m_y << ")";
	return oss.str();
}

std::string LibMath::Vector2::stringLong() const
{
	std::ostringstream oss;
	oss << "x = " << m_x << ", y = " << m_y;
	return oss.str();
}

void LibMath::Vector2::translate(Vector2 const& vector)
{
	m_x += vector.m_x;
	m_y += vector.m_y;
}

bool LibMath::operator==(Vector2 const& vector1, Vector2 const& vector2)
{
	if (vector1.m_x == vector2.m_x && vector1.m_y == vector2.m_y)
		return true;

	return false;
}

LibMath::Vector2 LibMath::operator+(Vector2 vector1, Vector2 const& vector2)
{
	vector1 += vector2;
	return vector1;
}

LibMath::Vector2 LibMath::operator-(Vector2 vector1, Vector2 const& vector2)
{
	vector1 -= vector2;
	return vector1;
}

LibMath::Vector2 LibMath::operator*(Vector2 vector1, Vector2 const& vector2)
{
	vector1 *= vector2;
	return vector1;
}

LibMath::Vector2 LibMath::operator/(Vector2 vector1, Vector2 const& vector2)
{
	vector1 /= vector2;
	return vector1;
}
