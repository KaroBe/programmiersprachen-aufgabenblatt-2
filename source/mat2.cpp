//mat2.cpp (programmiersprache-aufgabenblatt-2)

#include "mat2.hpp"
#include <cmath>

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
	float old_v11 = this->v11_;
	float old_v12 = this->v12_;
	float old_v21 = this->v21_;
	float old_v22 = this->v22_;

	this->v11_ = old_v11 * v.v11_ + old_v12 * v.v21_;
	this->v12_ = old_v11 * v.v12_ + old_v12 * v.v22_;

	this->v21_ = old_v21 * v.v11_ + old_v22 * v.v21_;
	this->v22_ = old_v21 * v.v12_ + old_v22 * v.v22_;

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