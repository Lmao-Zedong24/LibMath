#ifndef __LIBMATH__MATRIX__MATRIX3_H__
#define __LIBMATH__MATRIX__MATRIX3_H__

#include "MatrixInternal.h"

namespace LibMath
{
	class Matrix3 : public SquareMatrix
	{
	public:
					Matrix3(length_t) = delete;
					Matrix3(length_t, float) = delete;
					Matrix3();
		explicit	Matrix3(float scalar);
					Matrix3(const Matrix3& p_other);
					Matrix3(Matrix3&& p_other);
	};

	typedef Matrix3 Matrix3x3;
}

#endif // !__LIBMATH__MATRIX__MATRIX3_H__
