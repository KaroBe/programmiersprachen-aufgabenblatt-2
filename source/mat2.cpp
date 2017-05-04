//mat2.cpp (programmiersprache-aufgabenblatt-2)

#include "mat2.hpp"
#include <cmath>
#include <iostream>

//User construktor
Mat2::Mat2(float a, float b, float c, float d) :
	v11_{a},
	v12_{b},
	v21_{c},
	v22_{d} {}

//Default construktor -> Einheitsmatrix
Mat2::Mat2() :
	v11_{1.0f},
	v12_{0.0f},
	v21_{0.0f},
	v22_{1.0f} {}

//Matrizenmultiplikaton
Mat2& Mat2::operator *= (Mat2 const& v)
{
	float old_v11 = v11_;
	float old_v12 = v12_;
	float old_v21 = v21_;
	float old_v22 = v22_;

	v11_ = old_v11 * v.v11_ + old_v12 * v.v21_;
	v12_ = old_v11 * v.v12_ + old_v12 * v.v22_;

	v21_ = old_v21 * v.v11_ + old_v22 * v.v21_;
	v22_ = old_v21 * v.v12_ + old_v22 * v.v22_;

	return *this;
}

//Matrizenmultiplikation
Mat2 operator * (Mat2 const& u, Mat2 const& v)
{
	Mat2 result;

	result.v11_ = u.v11_ * v.v11_ + u.v12_ * v.v21_;
	result.v12_ = u.v11_ * v.v12_ + u.v12_ * v.v22_;

	result.v21_ = u.v21_ * v.v11_ + u.v22_ * v.v21_;
	result.v22_ = u.v21_ * v.v12_ + u.v22_ * v.v22_;

	return result;
}


//Determinante berechnen
float Mat2::det() const
{
	return (v11_*v22_ - v21_*v12_);
}

//Matrix * Vektor
Vec2 operator *( Mat2 const & m , Vec2 const & v )
{
	Vec2 result;

	result.x_ = m.v11_ * v.x_ + m.v12_ * v.y_;
	result.y_ = m.v21_ * v.x_ + m.v22_ * v.y_;

	return result;
}

Vec2 operator *( Vec2 const & v , Mat2 const & m )
{
	return m*v;
}

//Inverse berechnen
Mat2 inverse ( Mat2 const & m )
{
	if (m.det() == 0.0f)
	{
		std::cout << "Fehler: Matrix ist nicht invertierbar, det = 0";
		return m;
	}
	else
	{
		Mat2 res{};
		float det = m.det();

		res.v11_ = m.v22_ / det;
	 	res.v12_ = -m.v12_ / det;
		res.v21_ = -m.v21_ / det;
		res.v22_ = m.v11_ / det;

		return res;
	}
}

// Matrix transponieren
Mat2 transpose ( Mat2 const & m )
{
	Mat2 result = m;

	result.v12_ = m.v21_;
	result.v21_ = m.v12_;

	return result;
}

//Rotationsmatrix von Winkel in Bogenmaß
Mat2 make_rotation_mat2 ( float phi )
{
	return Mat2 {(float)cos(phi), (float)sin(phi),
				-1.0f * (float)sin(phi), (float)cos(phi)};
}
