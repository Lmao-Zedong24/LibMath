#ifndef __LIBMATH__MATRIX__MATRIX2_H__
#define __LIBMATH__MATRIX__MATRIX2_H__

#include "MatrixInternal.h"

namespace LibMath
{
	class Matrix2 : public SquareMatrix
	{
	public:
					Matrix2(length_t) = delete;
					Matrix2(length_t, float) = delete;
					Matrix2();
		explicit	Matrix2(float scalar);
					Matrix2(const Matrix2& p_other);
					Matrix2(Matrix2&& p_other);
	};

	typedef Matrix2 Matrix2x2;
}

#endif // !__LIBMATH__MATRIX__MATRIX2_H__