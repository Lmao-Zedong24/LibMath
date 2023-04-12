#ifndef __LIBMATH__VECTOR__VECTOR4_H__
#define __LIBMATH__VECTOR__VECTOR4_H__

#include <iostream>
#include <string>

#include "../Angle.h"

namespace LibMath
{
	class Vector4
	{
	public:
		Vector4() = default;
		explicit		Vector4(float);									// set all the component to the same value
		Vector4(float, float, float, float);					// set all component individually
		Vector4(Vector4 const&);
		~Vector4();

		static Vector4	zero();											// return a vector with all its component set to 0
		static Vector4	one();											// return a vector with all its component set to 1										// return a unit vector pointing backward

		Vector4& operator=(Vector4 const&);

		float& operator[](int);								// return this vector component value
		float			operator[](int) const;							// return this vector component value

		Vector4& operator+=(Vector4 const&);						// addition component wise
		Vector4& operator-=(Vector4 const&);						// substraction component wise
		Vector4& operator*=(Vector4 const&);						// multiplication component wise
		Vector4& operator/=(Vector4 const&);						// division component wise

		Radian			angleFrom(Vector4 const&) const;				// return smallest angle between 2 vector

		Vector4			cross(Vector4 const&) const;					// return a copy of the cross product result

		float			distanceFrom(Vector4 const&) const;				// return distance between 2 points
		float			distanceSquaredFrom(Vector4 const&) const;		// return square value of the distance between 2 points
		float			distance2DFrom(Vector4 const&) const;			// return the distance between 2 points on the X-Y axis only
		float			distance2DSquaredFrom(Vector4 const&) const;	// return the square value of the distance between 2 points points on the X-Y axis only

		float			dot(Vector4 const&) const;						// return dot product result

		bool			isLongerThan(Vector4 const&) const;				// return true if this vector magnitude is greater than the other
		bool			isShorterThan(Vector4 const&) const;			// return true if this vector magnitude is less than the other

		bool			isUnitVector() const;							// return true if this vector magnitude is 1

		float			magnitude() const;								// return vector magnitude
		float			magnitudeSquared() const;						// return square value of the vector magnitude

		void			normalize();									// scale this vector to have a magnitude of 1

		void			projectOnto(Vector4 const&);					// project this vector onto an other

		void			reflectOnto(Vector4 const&);					// reflect this vector by an other

		void			rotate(Radian, Radian, Radian);					// rotate this vector using euler angle apply in the z, x, y order
		void			rotate(Radian, Vector4 const&);					// rotate this vector around an arbitrary axis
		//void			rotate(Quaternion const&); todo quaternion		// rotate this vector using a quaternion rotor

		void			scale(Vector4 const&);							// scale this vector by a given factor

		std::string		string() const;									// return a string representation of this vector
		std::string		stringLong() const;								// return a verbose string representation of this vector

		void			translate(Vector4 const&);						// offset this vector by a given distance

		float m_x;
		float m_y;
		float m_z;
		float m_w;
	};

	bool			operator==(Vector4 const&, Vector4 const&);			// Vector3{ 1 } == Vector3::one()				// true					// return is 2 vectors have the same component

	Vector4			operator-(Vector4);									// - Vector3{ .5, 1.5, -2.5 }					// { -.5, -1.5, 2.5 }	// return a copy of a vector with all its component inverted

	Vector4			operator+(Vector4, Vector4 const&);					// Vector3{ .5, 1.5, -2.5 } + Vector3::one()	// { 1.5, 2.5, -1.5 }	// add 2 vectors component wise
	Vector4			operator-(Vector4, Vector4 const&);					// Vector3{ .5, 1.5, -2.5 } - Vector3{ 1 }		// { -.5, .5, -3.5 }	// substract 2 vectors component wise
	Vector4			operator*(Vector4, Vector4 const&);					// Vector3{ .5, 1.5, -2.5 } * Vector3::zero()	// { 0, 0, 0 }			// multiply 2 vectors component wise
	Vector4			operator*(const Vector4, float);
	Vector4			operator*(float, const Vector4);
	Vector4			operator/(Vector4, Vector4 const&);					// Vector3{ .5, 1.5, -2.5 } / Vector3{ 2 }		// { .25, .75, -1.25 }	// divide 2 vectors component wise

	std::ostream& operator<<(std::ostream&, Vector4 const&);			// cout << Vector3{ .5, 1.5, -2.5 }				// add a vector string representation to an output stream
	std::istream& operator>>(std::istream&, Vector4&);				// ifstream file{ save.txt }; file >> vector;	// parse a string representation from an input stream into a vector
}

#ifdef __LIBMATH__MATRIX__MATRIX4_H__
#include "Matrix4Vector4Operation.h"
#endif // __LIBMATH__MATRIX__MATRIX4_H__

#endif // !__LIBMATH__VECTOR__VECTOR4_H__
