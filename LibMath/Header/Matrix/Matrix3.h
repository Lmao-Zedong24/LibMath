#ifndef __LIBMATH__MATRIX__MATRIX3_H__
#define __LIBMATH__MATRIX__MATRIX3_H__

#include <vector>
#include "../Vector.h"

namespace LibMath
{
	class Matrix3
	{
	public:
							Matrix3() = default;
							Matrix3(Matrix3 const&);
							~Matrix3();

		Matrix3&			operator=(Matrix3 const&);

		float&				operator[](int);								// return this vector component value
		float				operator[](int) const;							// return this vector component value

		Matrix3&			operator+=(Matrix3 const&);
		Matrix3&			operator*=(Matrix3 const&);
		//Vector3&			operator*(Vector3);

		float*				m_values = new float[9];
	};
}

#endif // !__LIBMATH__MATRIX__MATRIX3_H__
