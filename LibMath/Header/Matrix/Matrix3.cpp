#include "Matrix3.h"

LibMath::Matrix3::Matrix3(Matrix3 const& matrix)
{
	for (int i = 0; i < 9; i++)
		m_values[i] = matrix.m_values[i];
}

LibMath::Matrix3::~Matrix3()
{
	delete[] m_values;
}

LibMath::Matrix3& LibMath::Matrix3::operator=(Matrix3 const& matrix)
{
	for (int i = 0; i < 9; i++)
		m_values[i] = matrix.m_values[i];

	return *this;
}

float& LibMath::Matrix3::operator[](int index)
{
	return m_values[index];
}

float LibMath::Matrix3::operator[](int index) const
{
	return m_values[index];
}

LibMath::Matrix3& LibMath::Matrix3::operator+=(Matrix3 const& matrix)
{
	for (int i = 0; i < 9; i++)
		m_values[i] += matrix.m_values[i];

	return *this;
}

LibMath::Matrix3& LibMath::Matrix3::operator*=(Matrix3 const& matrix)
{
	for (int s = 0; s < 9; s++) 
	{
		for (int i = 0; i < 3; i++)
		{
			for (int y = 0; y < 3; y++)
			{
				m_values[s] += matrix.m_values[i * 3 + y] * matrix.m_values[y * 3 + i];
			}
		}
	}

	return *this;
}

//LibMath::Vector3& LibMath::Matrix3::operator*(Vector3 vector)
//{
//	for (int s = 0; s < 3; s++)
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			vector[s] += m_values[s * 3 + i];
//		}
//	}
//
//	return vector;
//}

