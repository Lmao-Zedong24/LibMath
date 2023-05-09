#ifndef __LIBMATH__MATRIX__MATRIX4_H__
#define __LIBMATH__MATRIX__MATRIX4_H__

#include "MatrixInternal.h"

namespace LibMath
{
	class Radian;
	class Vector3;

	class Matrix4 : public SquareMatrix
	{
	public:
							Matrix4(length_t) = delete;
							Matrix4(length_t, float) = delete;
							Matrix4();
		explicit			Matrix4(float scalar);
							Matrix4(const Matrix4& p_other);
							Matrix4(Matrix4&& p_other);

		static Matrix4	translation(float x, float y, float z);
		static Matrix4	scaling(float x, float y, float z);
		static Matrix4	rotation(const Radian& angle, const Vector3& axis);
		static Matrix4	rotationEuler(const Radian& xAngle, const Radian& yAngle, const Radian& zAngle);
		static Matrix4	perspectiveProjection(const Radian& fovY, float aspect, float near, float far);

	private:
		static Matrix4	rotation(const Radian& yaw, const Radian& pitch, const Radian& roll);
	};

	typedef Matrix4 Matrix4x4;
}

#ifdef __LIBMATH__VECTOR__VECTOR4_H__
#include "Matrix4Vector4Operation.h"
#endif // __LIBMATH__MATRIX_H__

#endif // !__LIBMATH__MATRIX__MATRIX4_H__
