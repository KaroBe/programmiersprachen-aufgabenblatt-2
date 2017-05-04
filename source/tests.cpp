//tests.cpp (programmiersprache-aufgabenblatt-2)

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"


/*

TEST CASES for Constructors

*/

TEST_CASE("describe_custom_constructor", "[Vec2]")
{
	Vec2 v1{1.5f,1.5f};
	REQUIRE(1.5f == v1.x_);
	REQUIRE(1.5f == v1.y_);
}

TEST_CASE("describe_default_constructor", "[Vec2]")
{
	Vec2 v2;
	REQUIRE(0.0f == v2.x_);
	REQUIRE(0.0f == v2.y_);
}


/*

TEST CASES for Vec2 Operator Overloading

*/

TEST_CASE("describe_plus_operator", "[Vec2]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};
	
	Vec2 result1 = v0 + v2;
	Vec2 result2 = v1 + v2;

	REQUIRE(0.0f == result1.x_);
	REQUIRE(-2.0f == result1.y_);
	
	REQUIRE(1.0f == result2.x_);
	REQUIRE(0.0f == result2.y_);
}

TEST_CASE("describe_minus_operator", "[Vec2]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};
	
	Vec2 result1 = v0-v2;
	Vec2 result2 = v1-v2;

	REQUIRE(0.0f == result1.x_);
	REQUIRE(2.0f == result1.y_);
	
	REQUIRE(1.0f == result2.x_);
	REQUIRE(4.0f == result2.y_);
}

TEST_CASE("describe_skalar_mult_operator", "[Vec2]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};
	float s = 5.0f;

	Vec2 result1 = v0*s;
	Vec2 result2 = v1*s;

	REQUIRE(0.0f == result1.x_);
	REQUIRE(0.0f == result1.y_);
	
	REQUIRE(5.0f == result2.x_);
	REQUIRE(10.0f == result2.y_);
}

TEST_CASE("describe_division_operator", "[Vec2]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};
	float s = 5.0f;

	Vec2 result1 = v0/s;
	Vec2 result2 = v1/s;

	REQUIRE(0.0f == result1.x_);
	REQUIRE(0.0f == result1.y_);
	
	REQUIRE(0.2f == result2.x_);
	REQUIRE(0.4f == result2.y_);
}

TEST_CASE("describe_mult_operator_skalar_first", "[Vec2]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};
	float s = 5.0f;

	Vec2 result1 = v0*s;
	Vec2 result2 = v1*s;

	REQUIRE(0.0f == result1.x_);
	REQUIRE(0.0f == result1.y_);
	
	REQUIRE(5.0f == result2.x_);
	REQUIRE(10.0f == result2.y_);
}

TEST_CASE("describe_+=_operator", "[Vec2]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};
	float s = 5.0f;

	v0 += v1;
	v1 += v2;

	REQUIRE(1.0f == v0.x_);
	REQUIRE(2.0f == v0.y_);
	
	REQUIRE(1.0f == v1.x_);
	REQUIRE(0.0f == v1.y_);
}

TEST_CASE("describe_-=_operator", "[Vec2]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};
	float s = 5.0f;

	v0 -= v1;
	v1 -= v2;

	REQUIRE(-1.0f == v0.x_);
	REQUIRE(-2.0f == v0.y_);
	
	REQUIRE(1.0f == v1.x_);
	REQUIRE(4.0f == v1.y_);
}

TEST_CASE("describe_*=_operator", "[Vec2]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};
	float s = 5.0f;

	v0 *= s;
	v1 *= s;

	REQUIRE(0.0f == v0.x_);
	REQUIRE(0.0f == v0.y_);
	
	REQUIRE(5.0f == v1.x_);
	REQUIRE(10.0f == v1.y_);
}

TEST_CASE("describe_/=_operator", "[Vec2]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};
	float s = 5.0f;

	v0 /= s;
	v1 /= s;

	REQUIRE(0.0f == v0.x_);
	REQUIRE(0.0f == v0.y_);
	
	REQUIRE(0.2f == v1.x_);
	REQUIRE(0.4f == v1.y_);
}

/*

TEST CASE for Matrix Multiplikation

*/

TEST_CASE("describe_default_construktor_matrix", "[Mat2]")
{
	Mat2 mat0 {};
	
	REQUIRE(1.0f == mat0.v11_);
	REQUIRE(0.0f == mat0.v12_);
	REQUIRE(0.0f == mat0.v21_);
	REQUIRE(1.0f == mat0.v22_);	
}

TEST_CASE("describe_user_construktor_operator_matrix", "[Mat2]")
{
	Mat2 mat1 {1,2,3,4};
	Mat2 mat2 {0,0.5,1.5,-1};

	REQUIRE(1.0f == mat1.v11_);
	REQUIRE(2.0f == mat1.v12_);
	REQUIRE(3.0f == mat1.v21_);
	REQUIRE(4.0f == mat1.v22_);
	
	REQUIRE(0.0f == mat2.v11_);
	REQUIRE(0.5f == mat2.v12_);
	REQUIRE(1.5f == mat2.v21_);
	REQUIRE(-1.0f == mat2.v22_);
}

TEST_CASE("describe_*=_operator_matrix", "[Mat2]")
{
	Mat2 mat0 {};
	Mat2 mat1 {1,2,3,4};
	Mat2 mat2 {0,0.5,0.1,-1};

	mat0 *= mat1;
	mat1 *= mat2;

	REQUIRE(1.0f == mat0.v11_);
	REQUIRE(2.0f == mat0.v12_);
	REQUIRE(3.0f == mat0.v21_);
	REQUIRE(4.0f == mat0.v22_);
	
	REQUIRE(0.2f == mat1.v11_);
	REQUIRE(-1.5f == mat1.v12_);
	REQUIRE(0.4f == mat1.v21_);
	REQUIRE(-2.5f == mat1.v22_);
}


TEST_CASE("describe_*_operator_matrix", "[Mat2]")
{
	Mat2 mat0 {};
	Mat2 mat1 {1,2,3,4};
	Mat2 mat2 {0,0.5,0.1,-1};

	Mat2 res1 = mat0 * mat1;
	Mat2 res2 = mat1 * mat2;

	REQUIRE(1.0f == res1.v11_);
	REQUIRE(2.0f == res1.v12_);
	REQUIRE(3.0f == res1.v21_);
	REQUIRE(4.0f == res1.v22_);
	
	REQUIRE(0.2f == res2.v11_);
	REQUIRE(-1.5f == res2.v12_);
	REQUIRE(0.4f == res2.v21_);
	REQUIRE(-2.5f == res2.v22_);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

/*

TEST CASE for Matrix * Vektor / Vetor * Matrix
*/

TEST_CASE("describe_matrix*vektor", "[Mat2]")
{
	Mat2 mat1 {1,2,3,4};
	Mat2 mat2 {0,0.5,0.1,-1};

	Vec2 vec1 {1,2};

	Vec2 res1 = mat1 * vec1;
	Vec2 res2 = mat2 * vec1;

	REQUIRE(5.0f == res1.x_);
	REQUIRE(11.0f == res1.y_);
	
	REQUIRE(1.0f == res2.x_);
	REQUIRE(-1.9f == res2.y_);
}


TEST_CASE("describe_vektor*matrix", "[Mat2]")
{
	Mat2 mat1 {1,2,3,4};
	Mat2 mat2 {0,0.5,0.1,-1};

	Vec2 vec1 {1,2};

	Vec2 res1 = vec1 * mat1;
	Vec2 res2 = vec1 * mat2;

	REQUIRE(5.0f == res1.x_);
	REQUIRE(11.0f == res1.y_);
	
	REQUIRE(1.0f == res2.x_);
	REQUIRE(-1.9f == res2.y_);
}


/*

TEST CASE for Matrix

Determinante, Inverse,
Transponierte, Rotationsmatrix

*/


TEST_CASE("describe_det_matrix", "[Mat2]")
{
	Mat2 mat0 {};
	Mat2 mat1 {1,2,3,4};
	Mat2 mat2 {0,0.5,0.1,-1};

	REQUIRE(1.0f == mat0.det());
	REQUIRE(-2.0f == mat1.det());
	REQUIRE(-0.05f == mat2.det());
}

TEST_CASE("describe_transpose_matrix", "[Mat2]")
{
	Mat2 mat0 {};
	Mat2 mat1 {1,2,3,4};
	Mat2 mat2 {0,0.5,0.1,-1};

	Mat2 res0 = transpose(mat0);
	Mat2 res1 = transpose(mat1);
	Mat2 res2 = transpose(mat2);

	REQUIRE(1.0f == res1.v11_);
	REQUIRE(0.0f == res1.v12_);
	REQUIRE(1.0f == res1.v21_);
	REQUIRE(0.0f == res1.v22_);

	REQUIRE(1.0f == res1.v11_);
	REQUIRE(3.0f == res1.v12_);
	REQUIRE(2.0f == res1.v21_);
	REQUIRE(4.0f == res1.v22_);
	
	REQUIRE(0.0f == res1.v11_);
	REQUIRE(0.1f == res1.v12_);
	REQUIRE(0.5f == res1.v21_);
	REQUIRE(-1.0f == res1.v22_);
}

/*
TEST_CASE("describe_inverse_matrix", "[Mat2]")
{
	Mat2 mat0 {};
	Mat2 mat1 {1,2,3,4};
	Mat2 mat2 {0,0.5,0.1,-1};

	Mat2 res0 = inverse(mat0);
	Mat2 res1 = inverse(mat1);
	Mat2 res2 = inverse(mat2);

	REQUIRE(0.0f == res0.v11_);
	REQUIRE(1.0f == res0.v12_);
	REQUIRE(0.0f == res0.v21_);
	REQUIRE(1.0f == res0.v22_);

	REQUIRE(1.0f == res1.v11_);
	REQUIRE(2.0f == res1.v12_);
	REQUIRE(3.0f == res1.v21_);
	REQUIRE(4.0f == res1.v22_);

	REQUIRE(1.0f == res2.v11_);
	REQUIRE(2.0f == res2.v12_);
	REQUIRE(3.0f == res2.v21_);
	REQUIRE(4.0f == res2.v22_);

}

TEST_CASE("describe_rotate_matrix", "[Mat2]")
{
	Mat2 mat0 {};
	Mat2 mat1 {1,2,3,4};
	Mat2 mat2 {0,0.5,0.1,-1};

	Mat2 trans0 = make_rotation_mat2(phi);
	Mat2 trans1 = make_rotation_mat2(phi);
	Mat2 trans2 = make_rotation_mat2(phi);

	REQUIRE(1.0f == res1.v11_);
	REQUIRE(2.0f == res1.v12_);
	REQUIRE(3.0f == res1.v21_);
	REQUIRE(4.0f == res1.v22_);


	REQUIRE(1.0f == res1.v11_);
	REQUIRE(2.0f == res1.v12_);
	REQUIRE(3.0f == res1.v21_);
	REQUIRE(4.0f == res1.v22_);


	REQUIRE(1.0f == res1.v11_);
	REQUIRE(2.0f == res1.v12_);
	REQUIRE(3.0f == res1.v21_);
	REQUIRE(4.0f == res1.v22_);
}

*/