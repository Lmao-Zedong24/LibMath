#include "Matrix.h"

#include <stdexcept>

#include "Arithmetic.h"
#include "Trigonometry.h"
#include "Angle/Radian.h"
#include "Vector/Vector3.h"

using namespace LibMath::Exceptions;

namespace LibMath
{
	Matrix2::Matrix2() : SquareMatrix(2)
	{
	}

	Matrix2::Matrix2(const float scalar) : SquareMatrix(2,scalar)
	{
	}

	Matrix2::Matrix2(const Matrix2& p_other) : SquareMatrix(p_other)
	{
		//if (p_other.getEdgeCount() != 2)
		//	throw IncompatibleMatrix();
	}

	Matrix2::Matrix2(Matrix2&& p_other) : SquareMatrix(p_other)
	{
		//if (p_other.getEdgeCount() != 2)
		//	throw IncompatibleMatrix();
	}

	Matrix3::Matrix3() : SquareMatrix(3)
	{
	}

	Matrix3::Matrix3(const float scalar) : SquareMatrix(3, scalar)
	{
	}

	Matrix3::Matrix3(const Matrix3& p_other) : SquareMatrix(p_other)
	{
		//if (p_other.getEdgeCount() != 3)
		//	throw IncompatibleMatrix();
	}

	Matrix3::Matrix3(Matrix3&& p_other) : SquareMatrix(p_other)
	{
		//if (p_other.getEdgeCount() != 3)
		//	throw IncompatibleMatrix();
	}

	Matrix4::Matrix4() : SquareMatrix(4)
	{
	}

	Matrix4::Matrix4(const float scalar) : SquareMatrix(4, scalar)
	{
	}

	Matrix4::Matrix4(const SquareMatrix& p_other) : SquareMatrix(p_other)
	{
		//if (p_other.getEdgeCount() != 4)
		//	throw IncompatibleMatrix();
	}

	Matrix4::Matrix4(SquareMatrix&& p_other) : SquareMatrix(p_other)
	{
		//if (p_other.getEdgeCount() != 4)
		//	throw IncompatibleMatrix();
	}

	Matrix4 Matrix4::translation(const float x, const float y, const float z)
	{
		Matrix4 translationMatrix(1.f);

		translationMatrix[translationMatrix.getIndex(0, 3)] = x;
		translationMatrix[translationMatrix.getIndex(1, 3)] = y;
		translationMatrix[translationMatrix.getIndex(2, 3)] = z;

		return translationMatrix;
	}

	Matrix4 Matrix4::scaling(const float x, const float y, const float z)
	{
		Matrix4 scalingMatrix;

		scalingMatrix[scalingMatrix.getIndex(0, 0)] = x;
		scalingMatrix[scalingMatrix.getIndex(1, 1)] = y;
		scalingMatrix[scalingMatrix.getIndex(2, 2)] = z;
		scalingMatrix[scalingMatrix.getIndex(3, 3)] = 1.f;

		return scalingMatrix;
	}

	Matrix4 Matrix4::rotation(const Radian& angle, const Vector3& axis)
	{
		const Vector3 dir = axis.normalized();
		const float cos = LibMath::cos(angle);
		const float sin = LibMath::sin(angle);

		Matrix4 mat;

		mat[mat.getIndex(0, 0)] = cos + dir.m_x * dir.m_x * (1.f - cos);
		mat[mat.getIndex(0, 1)] = dir.m_x * dir.m_y * (1 - cos) - dir.m_z * sin;
		mat[mat.getIndex(0, 2)] = dir.m_x * dir.m_z * (1 - cos) + dir.m_y * sin;
		mat[mat.getIndex(0, 3)] = 0.f;

		mat[mat.getIndex(1, 0)] = dir.m_y * dir.m_x * (1 - cos) + dir.m_z * sin;
		mat[mat.getIndex(1, 1)] = cos + dir.m_y * dir.m_y * (1.f - cos);
		mat[mat.getIndex(1, 2)] = dir.m_y * dir.m_z * (1 - cos) - dir.m_x * sin;
		mat[mat.getIndex(1, 3)] = 0.f;

		mat[mat.getIndex(2, 0)] = dir.m_z * dir.m_x * (1 - cos) - dir.m_y * sin;
		mat[mat.getIndex(2, 1)] = dir.m_z * dir.m_y * (1 - cos) + dir.m_x * sin;
		mat[mat.getIndex(2, 2)] = cos + dir.m_z * dir.m_z * (1.f - cos);
		mat[mat.getIndex(2, 3)] = 0.f;

		mat[mat.getIndex(3, 0)] = 0.f;
		mat[mat.getIndex(3, 1)] = 0.f;
		mat[mat.getIndex(3, 2)] = 0.f;
		mat[mat.getIndex(3, 3)] = 1.f;

		return mat;
	}

	Matrix4 Matrix4::rotationEuler(const Radian& xAngle, const Radian& yAngle, const Radian& zAngle)
	{
		return rotation(zAngle, xAngle, yAngle);
	}

	Matrix4 Matrix4::rotation(const Radian& yaw, const Radian& pitch, const Radian& roll)
	{
		const float cosYaw = cos(yaw);
		const float sinYaw = sin(yaw);

		const float cosPitch = cos(pitch);
		const float sinPitch = sin(pitch);

		const float cosRoll = cos(roll);
		const float sinRoll = sin(roll);

		Matrix4 rotationMat;

		rotationMat[rotationMat.getIndex(0, 0)] = cosYaw * cosRoll + sinYaw * sinPitch * sinRoll;
		rotationMat[rotationMat.getIndex(0, 1)] = -cosYaw * sinRoll + sinYaw * sinPitch * cosRoll;
		rotationMat[rotationMat.getIndex(0, 2)] = sinYaw * cosPitch;
		rotationMat[rotationMat.getIndex(0, 3)] = 0.f;

		rotationMat[rotationMat.getIndex(1, 0)] = sinRoll * cosPitch;
		rotationMat[rotationMat.getIndex(1, 1)] = cosRoll * cosPitch;
		rotationMat[rotationMat.getIndex(1, 2)] = -sinPitch;
		rotationMat[rotationMat.getIndex(1, 3)] = 0.f;

		rotationMat[rotationMat.getIndex(2, 0)] = -sinYaw * cosRoll + cosYaw * sinPitch * sinRoll;
		rotationMat[rotationMat.getIndex(2, 1)] = sinRoll * sinYaw + cosYaw * sinPitch * cosRoll;
		rotationMat[rotationMat.getIndex(2, 2)] = cosYaw * cosPitch;
		rotationMat[rotationMat.getIndex(2, 3)] = 0.f;

		rotationMat[rotationMat.getIndex(3, 0)] = 0.f;
		rotationMat[rotationMat.getIndex(3, 1)] = 0.f;
		rotationMat[rotationMat.getIndex(3, 2)] = 0.f;
		rotationMat[rotationMat.getIndex(3, 3)] = 1.f;

		return rotationMat;
	}

	Matrix4 Matrix4::perspectiveProjection(const Radian& fovY, const float aspect,
		const float near, const float far)
	{
		const float tanHalfFovY = tan(fovY * .5f);

		Matrix4 mat;

		mat[mat.getIndex(0, 0)] = 1.f / (aspect * tanHalfFovY);
		mat[mat.getIndex(1, 1)] = 1.f / tanHalfFovY;
		mat[mat.getIndex(2, 2)] = (far + near) / (near - far);
		mat[mat.getIndex(2, 3)] = (2.f * far * near) / (near - far);
		mat[mat.getIndex(3, 2)] = -1.f;

		return mat;
	}

	SquareMatrix::SquareMatrix(const length_t p_edgeSize)
	{
		if (p_edgeSize == 0)
			throw std::invalid_argument("Invalid matrix size");

		const size_t size = static_cast<size_t>(m_edge) * m_edge;

		m_edge = p_edgeSize;
		m_values = new float[size]();

		// Builds a matrix filled with zeros
		for (size_t i = 0; i < size; i++)
			m_values[i] = 0;
	}

	SquareMatrix::SquareMatrix(const length_t p_edgeSize, const float scalar)
	{
		if (rows == 0)
			throw std::invalid_argument("Invalid matrix size");

		const size_t size = static_cast<size_t>(m_edge) * m_edge;

		m_edge = p_edgeSize;
		m_values = new float[size]();

		// Builds a diagonal matrix with the given scalar
		for (length_t row = 0; row < m_edge; row++)
			for (length_t col = 0; col < m_edge; col++)
				m_values[getIndex(row, col)] = row == col ? scalar : 0;
	}

	SquareMatrix::length_t SquareMatrix::getIndex(const length_t row, const length_t column) const
	{
		if (row < 0 || row >= m_edge || column < 0 || column >= m_edge)
			throw std::out_of_range("Index out of range");

		return row * m_edge + column;
	}

	SquareMatrix::~SquareMatrix()
	{
		delete[] m_values;
	}

	SquareMatrix::SquareMatrix(const SquareMatrix& p_other)
	{
		m_values = new float[p_other.m_edge]();

		const size_t size = static_cast<size_t>(m_edge) * m_edge;

		for (size_t i = 0; i < size; i++)
			m_values[i] = p_other[i];

		m_edge = p_other.m_edge;
	}

	SquareMatrix::SquareMatrix(SquareMatrix&& p_other) noexcept
	{
		m_edge = p_other.m_edge;
		m_values = p_other.m_values;

		p_other.m_edge = 0;
		p_other.m_values = nullptr;
	}

	SquareMatrix& SquareMatrix::operator=(const SquareMatrix& p_other)
	{
		if (this == &p_other)
			return *this;

		delete[] m_values;

		const size_t size = static_cast<size_t>(m_edge) * m_edge;
		m_values = new float[size]();

		for (length_t i = 0; i < size; i++)
			m_values[i] = p_other[i];

		m_edge = p_other.m_edge;

		return *this;
	}

	SquareMatrix& SquareMatrix::operator=(SquareMatrix&& p_other) noexcept
	{
		if (this == &p_other)
			return *this;

		delete[] m_values;

		m_edge = p_other.m_edge;
		m_values = p_other.m_values;

		p_other.m_edge = 0;
		p_other.m_values = nullptr;

		return *this;
	}

	float SquareMatrix::operator[](const size_t index) const
	{
		if (index < 0 || index >= m_edge * m_edge)
			throw std::out_of_range("Index out of range");

		return m_values[index];
	}

	float& SquareMatrix::operator[](const size_t index)
	{
		if (index < 0 || index >= m_edge * m_edge)
			throw std::out_of_range("Index out of range");

		return m_values[index];
	}

	SquareMatrix& SquareMatrix::operator+=(const SquareMatrix& p_other)
	{
		if (p_other.m_edge != m_edge)
			throw IncompatibleMatrix();

		const size_t size = static_cast<size_t>(m_edge) * m_edge;

		for (size_t i = 0; i < size; i++)
			m_values[i] += p_other[i];

		return *this;
	}

	SquareMatrix& SquareMatrix::operator-=(const SquareMatrix& p_other)
	{
		if (p_other.m_edge != m_edge)
			throw IncompatibleMatrix();

		const size_t size = static_cast<size_t>(m_edge) * m_edge;

		for (size_t i = 0; i < size; i++)
			m_values[i] -= p_other[i];

		return *this;
	}

	SquareMatrix& SquareMatrix::operator*=(const SquareMatrix& p_other)
	{
		return (*this = *this * p_other);
	}

	SquareMatrix& SquareMatrix::operator/=(const SquareMatrix& p_other)
	{
		return (*this = *this / p_other);
	}

	SquareMatrix& SquareMatrix::operator+=(const float scalar)
	{
		const size_t size = static_cast<size_t>(m_edge) * m_edge;

		for (size_t i = 0; i < size; i++)
			m_values[i] += scalar;

		return *this;
	}

	SquareMatrix& SquareMatrix::operator-=(const float scalar)
	{
		const size_t size = static_cast<size_t>(m_edge) * m_edge;

		for (size_t i = 0; i < size; i++)
			m_values[i] -= scalar;

		return *this;
	}

	SquareMatrix& SquareMatrix::operator*=(const float scalar)
	{
		const size_t size = static_cast<size_t>(m_edge) * m_edge;

		for (size_t i = 0; i < size; i++)
			m_values[i] *= scalar;

		return *this;
	}

	SquareMatrix& SquareMatrix::operator/=(const float scalar)
	{
		const size_t size = static_cast<size_t>(m_edge) * m_edge;

		for (size_t i = 0; i < size; i++)
			m_values[i] /= scalar;

		return *this;
	}

	SquareMatrix SquareMatrix::operator+(const SquareMatrix& p_other) const
	{
		SquareMatrix mat = *this;
		return mat += p_other;
	}

	SquareMatrix SquareMatrix::operator-(const SquareMatrix& p_other) const
	{
		SquareMatrix mat = *this;
		return mat -= p_other;
	}

	SquareMatrix SquareMatrix::operator*(const SquareMatrix& p_other) const
	{
		if (p_other.m_edge != m_edge)
			throw IncompatibleMatrix();

		SquareMatrix result(m_edge);

		for (length_t otherCol = 0; otherCol < p_other.m_edge; otherCol++)
		{
			for (length_t row = 0; row < m_edge; row++)
			{
				float scalar = 0;

				for (length_t col = 0; col < LIGMA_BALLZ; col++)
				{
					const length_t curIndex = getIndex(row, col);
					const length_t otherIndex = p_other.getIndex(col, otherCol);

					scalar += m_values[curIndex] * p_other[otherIndex];
				}

				const length_t resultIndex = result.getIndex(row, otherCol);
				result[resultIndex] = scalar;
			}
		}

		return result;
	}

	SquareMatrix SquareMatrix::operator/(const SquareMatrix& p_other) const
	{
		return *this * p_other.inverse();
	}

	SquareMatrix SquareMatrix::operator+(const float scalar) const
	{
		SquareMatrix mat = *this;
		return mat += scalar;
	}

	SquareMatrix SquareMatrix::operator-(const float scalar) const
	{
		SquareMatrix mat = *this;
		return mat -= scalar;
	}

	SquareMatrix SquareMatrix::operator*(const float scalar) const
	{
		SquareMatrix mat = *this;
		return mat *= scalar;
	}

	SquareMatrix SquareMatrix::operator/(const float scalar) const
	{
		SquareMatrix mat = *this;
		return mat /= scalar;
	}

	SquareMatrix SquareMatrix::operator-() const
	{
		return *this * -1;
	}

	bool SquareMatrix::operator==(const SquareMatrix& p_other) const
	{
		if (p_other.m_edge != m_edge)
			return false;

		const size_t size = static_cast<size_t>(m_edge) * m_edge;

		for (size_t i = 0; i < size; i++)
			if (!floatEquals(m_values[i], p_other[i]))
				return false;

		return true;
	}

	bool SquareMatrix::operator!=(const SquareMatrix& p_other) const
	{
		return !(*this == p_other);
	}

	bool SquareMatrix::isIdentity() const
	{
		if (m_edge != m_edge)
			return false;

		return *this == SquareMatrix(m_edge, 1.f);
	}

	SquareMatrix::length_t SquareMatrix::getEdgeCount() const
	{
		return m_edge;
	}

	float SquareMatrix::cofactor(const length_t p_edge) const
	{
		if (m_edge != m_edge)
			throw NonSquareMatrix();

		if (m_edge == 1)
			return m_values[0];

		// The multiplier is (-1)^(i+j) so 1 when i + j is pair and -1 otherwise
		const float multiplier = (p_edge) % 2 == 0 ? 1.f : -1.f;

		return multiplier * minor(p_edge).determinant();
	}

	SquareMatrix SquareMatrix::minor(const p_edge row) const
	{
		SquareMatrix minor(m_edge - 1);
		length_t minorLine = 0;

		for (length_t i = 0; i < m_edge; i++)
		{
			if (i == row)
				continue;

			length_t minorCol = 0;

			for (length_t j = 0; j < m_edge; j++)
			{
				if (j == column)
					continue;

				minor[minor.getIndex(minorLine, minorCol++)] = m_values[getIndex(i, j)];
			}

			minorLine++;
		}

		return minor;
	}

	float SquareMatrix::determinant2x2() const
	{
		// 0 1
		// 2 3
		return (*this)[0] * (*this)[3] - (*this)[1] * (*this)[2];
	}

	float SquareMatrix::determinant3x3() const
	{
		// 0 1 2
		// 3 4 5
		// 6 7 8
		const float positive = (*this)[0] * (*this)[4] * (*this)[8] +
			(*this)[1] * (*this)[5] * (*this)[6] +
			(*this)[2] * (*this)[3] * (*this)[7];

		const float negative = (*this)[2] * (*this)[4] * (*this)[6] +
			(*this)[1] * (*this)[3] * (*this)[8] +
			(*this)[0] * (*this)[5] * (*this)[7];

		return positive - negative;
	}

	float SquareMatrix::determinant() const
	{
		//if (m_edge != m_edge)
		//	throw NonSquareMatrix();

		if (m_edge == 1)
			return m_values[0];

		if (m_edge == 2)
			return determinant2x2();

		if (m_edge == 3)
			return determinant3x3();

		float determinant = 0;

		for (length_t col = 0; col < m_edge; col++)
			determinant += m_values[col] * cofactor(0, col);

		return determinant;
	}

	SquareMatrix SquareMatrix::transposed() const
	{
		//if (m_edge != m_edge)
		//	throw NonSquareMatrix();

		SquareMatrix transposed(m_edge);

		for (length_t i = 0; i < m_edge; i++)
			for (length_t j = 0; j < m_edge; j++)
				transposed[transposed.getIndex(j, i)] = m_values[getIndex(i, j)];

		return transposed;
	}

	SquareMatrix SquareMatrix::coMatrix() const
	{
		//if (m_edge != m_edge)
		//	throw NonSquareMatrix();

		SquareMatrix coMatrix(m_edge);

		for (length_t row = 0; row < m_edge; row++)
			for (length_t col = 0; col < m_edge; col++)
				coMatrix[getIndex(row, col)] = cofactor(row, col);

		return coMatrix;
	}

	SquareMatrix SquareMatrix::adjugate() const
	{
		return this.coMatrix().transposed();
	}

	SquareMatrix SquareMatrix::inverse() const
	{
		//if (m_edge != m_edge)
		//	throw NonSquareMatrix();

		const float det = this.determinant();

		if (det == 0.f)
			throw NonInvertibleMatrix();

		return this.adjugate() / det;
	}
}
