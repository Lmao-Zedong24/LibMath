#ifndef __LIBMATH__VECTOR__VECTOR2_H__
#define __LIBMATH__VECTOR__VECTOR2_H__

#include <iostream>
#include <string>

#include "Angle/Radian.h"

namespace LibMath
{
	class Vector2
	{
	public:
						Vector2() = default;
		explicit		Vector2(float);									// set all the component to the same value
						Vector2(float, float);					// set all component individually
						Vector2(Vector2 const&);
						~Vector2();

		static Vector2	zero();											// return a vector with all its component set to 0
		static Vector2	one();											// return a vector with all its component set to 1
		static Vector2	up();											// return a unit vector pointing upward
		static Vector2	down();											// return a unit vector pointing downward
		static Vector2	left();											// return a unit vector pointing left
		static Vector2	right();										// return a unit vector pointing right

		Vector2& operator=(Vector2 const&);

		float&	operator[](int);								// return this vector component value
		float	operator[](int) const;							// return this vector component value

		Vector2& operator+=(Vector2 const&);						// addition component wise
		Vector2& operator-=(Vector2 const&);						// substraction component wise
		Vector2& operator*=(Vector2 const&);						// multiplication component wise
		Vector2& operator/=(Vector2 const&);						// division component wise

		Radian			angleFrom(Vector2 const&) const;				// return smallest angle between 2 vector

		float			distanceFrom(Vector2 const&) const;				// return distance between 2 points
		float			distanceSquaredFrom(Vector2 const&) const;		// return square value of the distance between 2 points
		float			distance2DFrom(Vector2 const&) const;			// return the distance between 2 points on the X-Y axis only
		float			distance2DSquaredFrom(Vector2 const&) const;	// return the square value of the distance between 2 points points on the X-Y axis only

		float			dot(Vector2 const&) const;						// return dot product result

		bool			isLongerThan(Vector2 const&) const;				// return true if this vector magnitude is greater than the other
		bool			isShorterThan(Vector2 const&) const;			// return true if this vector magnitude is less than the other

		bool			isUnitVector() const;							// return true if this vector magnitude is 1

		float			magnitude() const;								// return vector magnitude
		float			magnitudeSquared() const;						// return square value of the vector magnitude

		void			normalize();									// scale this vector to have a magnitude of 1

		void			projectOnto(Vector2 const&);					// project this vector onto an other

		void			reflectOnto(Vector2 const&);					// reflect this vector by an other

		void			rotate(Radian, Radian, Radian);					// rotate this vector using euler angle apply in the z, x, y order
		void			rotate(Radian, Vector2 const&);					// rotate this vector around an arbitrary axis
		//void			rotate(Quaternion const&); todo quaternion		// rotate this vector using a quaternion rotor

		void			scale(Vector2 const&);							// scale this vector by a given factor

		std::string		string() const;									// return a string representation of this vector
		std::string		stringLong() const;								// return a verbose string representation of this vector

		void			translate(Vector2 const&);						// offset this vector by a given distance

		float m_x;
		float m_y;
	};

	bool			operator==(Vector2 const&, Vector2 const&);			// Vector3{ 1 } == Vector3::one()				// true					// return is 2 vectors have the same component

	Vector2			operator-(Vector2);									// - Vector3{ .5, 1.5, -2.5 }					// { -.5, -1.5, 2.5 }	// return a copy of a vector with all its component inverted

	Vector2			operator+(Vector2, Vector2 const&);					// Vector3{ .5, 1.5, -2.5 } + Vector3::one()	// { 1.5, 2.5, -1.5 }	// add 2 vectors component wise
	Vector2			operator-(Vector2, Vector2 const&);					// Vector3{ .5, 1.5, -2.5 } - Vector3{ 1 }		// { -.5, .5, -3.5 }	// substract 2 vectors component wise
	Vector2			operator*(Vector2, Vector2 const&);					// Vector3{ .5, 1.5, -2.5 } * Vector3::zero()	// { 0, 0, 0 }			// multiply 2 vectors component wise
	Vector2			operator/(Vector2, Vector2 const&);					// Vector3{ .5, 1.5, -2.5 } / Vector3{ 2 }		// { .25, .75, -1.25 }	// divide 2 vectors component wise

	std::ostream& operator<<(std::ostream&, Vector2 const&);			// cout << Vector3{ .5, 1.5, -2.5 }				// add a vector string representation to an output stream
	std::istream& operator>>(std::istream&, Vector2&);				// ifstream file{ save.txt }; file >> vector;	// parse a string representation from an input stream into a vector
}

#endif // !__LIBMATH__VECTOR__VECTOR2_H__