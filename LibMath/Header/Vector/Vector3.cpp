#include "Vector3.h"

#include "Trigonometry.h"
#include "Arithmetic.h"
#include <string>
#include <sstream>

LibMath::Vector3::Vector3(float value)
{
	m_x = value;
	m_y = value;
	m_z = value;
}

LibMath::Vector3::Vector3(float valueX, float valueY, float valueZ)
{
	m_x = valueX;
	m_y = valueY;
	m_z = valueZ;
}

LibMath::Vector3::Vector3(Vector3 const& vector3)
{
	m_x = vector3.m_x;
	m_y = vector3.m_y;
	m_z = vector3.m_z;
}

LibMath::Vector3::~Vector3()
{

}

LibMath::Vector3 LibMath::Vector3::zero()
{
	Vector3 newVector(0, 0, 0);
	return newVector;
}

LibMath::Vector3 LibMath::Vector3::one()
{
	Vector3 newVector(1, 1, 1);
	return newVector;
}

LibMath::Vector3 LibMath::Vector3::up()
{
	Vector3 newVector(0, 1, 0);
	return newVector;
}

LibMath::Vector3 LibMath::Vector3::down()
{
	Vector3 newVector(0, -1, 0);
	return newVector;
}

LibMath::Vector3 LibMath::Vector3::left()
{
	Vector3 newVector(-1, 0, 0);
	return newVector;
}

LibMath::Vector3 LibMath::Vector3::right()
{
	Vector3 newVector(1, 0, 0);
	return newVector;
}

LibMath::Vector3 LibMath::Vector3::front()
{
	Vector3 newVector(0, 0, 1);
	return newVector;
}

LibMath::Vector3 LibMath::Vector3::back()
{
	Vector3 newVector(0, 0, -1);
	return newVector;
}

LibMath::Vector3& LibMath::Vector3::operator=(Vector3 const& vector)
{
	m_x = vector.m_x;
	m_y = vector.m_y;
	m_z = vector.m_z;

	return *this;
}

float& LibMath::Vector3::operator[](int index)
{
	switch (index)
	{
	case 0:
		return m_x;
		break;
	case 1:
		return m_y;
		break;
	case 2:
		return m_z;
		break;
	default:
		throw;
		break;
	}
}

float LibMath::Vector3::operator[](int index) const
{
	switch (index)
	{
	case 0:
		return m_x;
		break;
	case 1:
		return m_y;
		break;
	case 2:
		return m_z;
		break;
	default:
		throw;
		break;
	}
}

LibMath::Vector3& LibMath::Vector3::operator+=(Vector3 const& vector)
{
	m_x += vector.m_x;
	m_y += vector.m_y;
	m_z += vector.m_z;

	return *this;
}

LibMath::Vector3& LibMath::Vector3::operator-=(Vector3 const& vector)
{
	m_x -= vector.m_x;
	m_y -= vector.m_y;
	m_z -= vector.m_z;

	return *this;
}

LibMath::Vector3& LibMath::Vector3::operator*=(Vector3 const& vector)
{
	m_x *= vector.m_x;
	m_y *= vector.m_y;
	m_z *= vector.m_z;

	return *this;
}

LibMath::Vector3& LibMath::Vector3::operator/=(Vector3 const& vector)
{
	m_x /= vector.m_x;
	m_y /= vector.m_y;
	m_z /= vector.m_z;

	return *this;
}

LibMath::Radian LibMath::Vector3::angleFrom(Vector3 const& vector) const
{
	Radian angle(acos(this->dot(vector) / (magnitude() * vector.magnitude())));

	return angle;
}

LibMath::Vector3 LibMath::Vector3::cross(Vector3 const& vector) const
{
	Vector3 newVector;

	newVector.m_x = m_y * vector.m_z - m_z * vector.m_y;
	newVector.m_y = m_x * vector.m_z - m_z * vector.m_x;
	newVector.m_z = m_x * vector.m_y - m_y * vector.m_x;

	return newVector;
}

float LibMath::Vector3::distanceFrom(Vector3 const& vector) const
{
	return squareRoot((m_x - vector.m_x) * (m_x - vector.m_x) + (m_y - vector.m_y) * (m_y - vector.m_y) + (m_z - vector.m_z) * (m_z - vector.m_z));
}

float LibMath::Vector3::distanceSquaredFrom(Vector3 const& vector) const
{
	return (m_x - vector.m_x) * (m_x - vector.m_x) + (m_y - vector.m_y) * (m_y - vector.m_y) + (m_z - vector.m_z) * (m_z - vector.m_z);
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

float LibMath::Vector3::dot(Vector3 const& vector) const
{
	float dotProduct;

	dotProduct = m_x * vector.m_x + m_y * vector.m_y + m_z * vector.m_z;

	return dotProduct;
}

bool LibMath::Vector3::isLongerThan(Vector3 const& vector) const
{
	if (magnitudeSquared() > vector.magnitudeSquared())
		return true;
	else
		return false;
}

bool LibMath::Vector3::isShorterThan(Vector3 const& vector) const
{
	if (magnitudeSquared() < vector.magnitudeSquared())
		return true;
	else
		return false;
}

bool LibMath::Vector3::isUnitVector() const
{
	if (magnitudeSquared() == 1.0f)
		return true;
	else
		return false;
}

float LibMath::Vector3::magnitude() const
{
	return squareRoot(m_x * m_x + m_y * m_y + m_z + m_z);
}

float LibMath::Vector3::magnitudeSquared() const
{
	return m_x * m_x + m_y * m_y + m_z + m_z;
}

void LibMath::Vector3::normalize()
{
	m_x /= magnitude();
	m_y /= magnitude();
	m_z /= magnitude();
}

void LibMath::Vector3::rotate(Radian, Radian, Radian)
{

}

void LibMath::Vector3::rotate(Radian, Vector3 const&)
{

}

void LibMath::Vector3::scale(Vector3 const& vector)
{
	m_x += vector.m_x;
	m_y += vector.m_y;
	m_z += vector.m_z;
}

std::string LibMath::Vector3::string() const
{
	std::ostringstream oss;
	oss << "( " << m_x << ", " << m_y << ", " << m_z << ")";
	return oss.str();
}

std::string LibMath::Vector3::stringLong() const
{
	std::ostringstream oss;
	oss << "x = " << m_x << ", y = " << m_y << ", z = " << m_z;
	return oss.str();
}

void LibMath::Vector3::translate(Vector3 const& vector)
{
	m_x += vector.m_x;
	m_y += vector.m_y;
	m_z += vector.m_z;
}

bool LibMath::operator==(Vector3 const& vector1, Vector3 const& vector2)
{
	if (vector1.m_x == vector2.m_x && vector1.m_y == vector2.m_y && vector1.m_z == vector2.m_z)
		return true;

	return false;
}

LibMath::Vector3 LibMath::operator-(Vector3 vector)
{
	vector.m_x *= -1;
	vector.m_y *= -1;
	vector.m_z *= -1;

	return vector;
}

LibMath::Vector3 LibMath::operator+(Vector3 vector1, Vector3 const& vector2)
{
	vector1 += vector2;
	return vector1;
}

LibMath::Vector3 LibMath::operator-(Vector3 vector1, Vector3 const& vector2)
{
	vector1 -= vector2;
	return vector1;
}

LibMath::Vector3 LibMath::operator*(Vector3 vector1, Vector3 const& vector2)
{
	vector1 *= vector2;
	return vector1;
}

LibMath::Vector3 LibMath::operator/(Vector3 vector1, Vector3 const& vector2)
{
	vector1 /= vector2;
	return vector1;
}
