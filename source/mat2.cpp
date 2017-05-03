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
Vec2& Vec2::operator *= (Vec2 const& v)
{
	float old_v11 = this->v11_;
	float old_v12 = this->v12_;
	float old_v11 = this->v21_;
	float old_v11 = this->v22_;

	this->v11_ = old_v11 * v.v11_ + old_v12 * v.v21;
	this->v12_ = old_v11 * v.v12_ + old_v12 * v.v22;

	this->v21_ = old_v21 * v.v11_ + old_v22 * v.v21;
	this->v22_ = old_v21 * v.v12_ + old_v22 * v.v22;

	return *this;
}

//Matrizenmultiplikation
Vec2 operator * (Vec2 const& u, Vec2 const& v)
{
	Vec2 result;

	result.v11_ = u.v11 * v.v11_ + u.v12 * v.v21;
	result.v12_ = u.v11 * v.v12_ + u.v12 * v.v22;

	result.v21_ = u.v21 * v.v11_ + u.v22 * v.v21;
	result.v22_ = u.v21 * v.v12_ + u.v22 * v.v22;

	return result;
}