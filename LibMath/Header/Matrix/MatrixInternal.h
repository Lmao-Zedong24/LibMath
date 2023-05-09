#ifndef __LIBMATH__MATRIX_MATRIXINTERNAL_H__
#define __LIBMATH__MATRIX_MATRIXINTERNAL_H__
#include <exception>

namespace LibMath
{
	namespace Exceptions
	{
		class IncompatibleMatrix : public std::exception
		{
		public:
			IncompatibleMatrix() noexcept
				: exception("Incompatible matrix")
			{
			}
		};

		class NonSquareMatrix : public std::exception
		{
		public:
			NonSquareMatrix() noexcept
				: exception("Non-square matrix")
			{
			}
		};

		class NonInvertibleMatrix : public std::exception
		{
		public:
			NonInvertibleMatrix() noexcept
				: exception("Non-invertible matrix")
			{
			}
		};
	}

	class SquareMatrix
	{
	protected:
		using			length_t = int;

						SquareMatrix(length_t p_size);
						SquareMatrix(length_t rows, length_t columns, float scalar);
						SquareMatrix(SquareMatrix const& p_other);
						SquareMatrix(SquareMatrix&& p_other) noexcept;
		virtual			~SquareMatrix();

		SquareMatrix&			operator=(SquareMatrix const& p_other);
		SquareMatrix&			operator=(SquareMatrix&& p_other) noexcept;

		float			operator[](size_t index) const;
		float&			operator[](size_t index);

		SquareMatrix&			operator+=(SquareMatrix const& p_other);
		SquareMatrix&			operator-=(SquareMatrix const& p_other);
		SquareMatrix&			operator*=(SquareMatrix const& p_other);
		SquareMatrix&			operator/=(SquareMatrix const& p_other);

		SquareMatrix&			operator+=(float scalar);
		SquareMatrix&			operator-=(float scalar);
		SquareMatrix&			operator*=(float scalar);
		SquareMatrix&			operator/=(float scalar);

		SquareMatrix			operator+(SquareMatrix const& p_other) const;
		SquareMatrix			operator-(SquareMatrix const& p_other) const;
		SquareMatrix			operator*(SquareMatrix const& p_other) const;
		SquareMatrix			operator/(SquareMatrix const& p_other) const;

		SquareMatrix			operator+(float scalar) const;
		SquareMatrix			operator-(float scalar) const;
		SquareMatrix			operator*(float scalar) const;
		SquareMatrix			operator/(float scalar) const;

		SquareMatrix			operator-() const;

		bool			operator==(const SquareMatrix& p_other) const;
		bool			operator!=(const SquareMatrix& p_other) const;
		bool			isIdentity() const;

		length_t		getEdgeCount() const;
		length_t		getIndex(length_t row, length_t column) const;

		float			determinant() const;
		float			cofactor(length_t row, length_t column) const;

		SquareMatrix			minor(length_t row, length_t column) const;
		SquareMatrix			transposed() const;
		SquareMatrix			coMatrix() const;
		SquareMatrix			adjugate() const;
		SquareMatrix			inverse() const;

		float			determinant2x2() const;
		float			determinant3x3() const;

		length_t		m_edge;
		float*			m_values;
	};
}

#endif // !__LIBMATH__MATRIX_MATRIXINTERNAL_H__