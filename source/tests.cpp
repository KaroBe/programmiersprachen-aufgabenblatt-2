//tests.cpp (programmiersprache-aufgabenblatt-2)

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

#include <iostream>
#include <cmath>

/*

TEST CASES for Vec2 Constructors

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
	float zero = 0.0f;

	Vec2 result1 = v0/s;
	Vec2 result2 = v1/s;
	Vec2 result3 = v0/zero;

	REQUIRE(0.0f == result1.x_);
	REQUIRE(0.0f == result1.y_);

	REQUIRE(0.2f == result2.x_);
	REQUIRE(0.4f == result2.y_);

	REQUIRE(0.0f == result3.x_);
	REQUIRE(0.0f == result3.y_);
	
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
	float zero = 0.0f;

	v0 /= s;
	v1 /= s;
	v2 /= zero;

	REQUIRE(0.0f == v0.x_);
	REQUIRE(0.0f == v0.y_);
	
	REQUIRE(0.2f == v1.x_);
	REQUIRE(0.4f == v1.y_);

	REQUIRE(0.0f == v0.x_);
	REQUIRE(0.0f == v0.y_);
	
}

/*

TEST CASE for Matrix Constructors

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

/*

TEST CASE for Matrix Multiplikation

*/

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

TEST CASE for Matrix * Vektor and Vetor * Matrix

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

	REQUIRE(1.0f == res0.v11_);
	REQUIRE(0.0f == res0.v12_);
	REQUIRE(0.0f == res0.v21_);
	REQUIRE(1.0f == res0.v22_);

	REQUIRE(1.0f == res1.v11_);
	REQUIRE(3.0f == res1.v12_);
	REQUIRE(2.0f == res1.v21_);
	REQUIRE(4.0f == res1.v22_);
	
	REQUIRE(0.0f == res2.v11_);
	REQUIRE(0.1f == res2.v12_);
	REQUIRE(0.5f == res2.v21_);
	REQUIRE(-1.0f == res2.v22_);
}

TEST_CASE("describe_inverse_matrix", "[Mat2]")
{
	Mat2 mat0 {}; //mat0 ist nicht invertierbar, return mat0
	Mat2 mat1 {1.0f,2.0f,3.0f,4.0f};
	Mat2 mat2 {0,0.5,0.1,-1};
	
	std::cout << mat1.v11_;
	std::cout << mat1.v12_;
	std::cout << mat1.v21_;
	std::cout << mat1.v22_;


	Mat2 res0 = inverse(mat0);
	Mat2 erg = inverse(mat1);
	Mat2 res2 = inverse(mat2);

	std::cout << erg.v11_;
	std::cout << erg.v12_;
	std::cout << erg.v21_;
	std::cout << erg.v22_;

	REQUIRE(1.0f == res0.v11_);
	REQUIRE(0.0f == res0.v12_);
	REQUIRE(0.0f == res0.v21_);
	REQUIRE(1.0f == res0.v22_);

	REQUIRE(-2.0f == erg.v11_);
	REQUIRE(1.0f == erg.v12_);
	REQUIRE((3.0f/2.0f) == erg.v21_);
	REQUIRE((-1.0f/2.0f) == erg.v22_);

	REQUIRE(20.0f == res2.v11_);
	REQUIRE(10.0f == res2.v12_);
	REQUIRE(2.0f == res2.v21_);
	REQUIRE(0.0f == res2.v22_);
}

TEST_CASE("describe_rotate_matrix", "[Mat2]")
{
	Mat2 res1 = make_rotation_mat2(1.0f);

	REQUIRE(0.54030f == Approx(res1.v11_));
	REQUIRE(0.84147f == Approx(res1.v12_));
	REQUIRE(-0.84147f == Approx(res1.v21_));
	REQUIRE(0.54030f == Approx(res1.v22_));
}

/*

TEST CASES for Color Constructors

*/

TEST_CASE("describe_construstors_color", "[Color]")
{
	Color c1{0.5f};
	REQUIRE(0.5f == c1.r_);
	REQUIRE(0.5f == c1.g_);
	REQUIRE(0.5f == c1.b_);

	Color c2{0.0f, 0.5f, 1.0f};

	REQUIRE(0.0f == c2.r_);
	REQUIRE(0.5f == c2.g_);
	REQUIRE(1.0f == c2.b_);
}

/*

TEST CASES for Circle Constructors

*/

TEST_CASE("describe_constructor_getter_circle", "[Circle]")
{
	Circle c1
	{
		Vec2{1.0f,2.0f},
		5.0f,
		Color{0.5f,0.5f,0.5f}
	};

	REQUIRE(1.0f == c1.getCenter().x_);
	REQUIRE(2.0f == c1.getCenter().y_);

	REQUIRE(5.0f == c1.getRadius());

	REQUIRE(0.5f == c1.getColor().r_);
	REQUIRE(0.5f == c1.getColor().g_);
	REQUIRE(0.5f == c1.getColor().b_);

}

/*

TEST CASES for Circle Circumference

*/

TEST_CASE("describe_circumference_circle","[Circle]")
{
	Circle c1
	{
		Vec2{1.0f,2.0f},
		5.0f,
		Color{0.5f,0.5f,0.5f}
	};

	REQUIRE(31.415927f == Approx(c1.circumference()));
	
	Circle c2
	{
		Vec2{1.0f,2.0f},
		10.0f,
		Color{0.5f,0.5f,0.5f}
	};

	REQUIRE(62.831853f == Approx(c2.circumference()));
}

/*

TEST CASES for Circle is point inside

*/

TEST_CASE("describe_is_inside_circle", "[Circle]")
{
	Circle circle
	{
      Vec2 {400.0f, 400.0f},
      200.0f,
      Color {1.0f, 0.0f, 0.0f} //rot
    };

    Vec2 point1 {300,300};
    Vec2 point2 {0,0};
	
	REQUIRE(true == circle.is_inside(point1));
	REQUIRE(false == circle.is_inside(point2));
}

/*

TEST CASES for Rectangle Constructors, Circumference

*/


TEST_CASE("describe_constructor_getter_rectangle", "[Rectangle]")
{
	Rectangle c1
	{
		Vec2{1.0f,2.0f},
		Vec2{4.0f,5.0f},
		Color{0.5f,0.5f,0.5f}
	};

	REQUIRE(1.0f == c1.getMin().x_);
	REQUIRE(2.0f == c1.getMin().y_);

	REQUIRE(4.0f == c1.getMax().x_);
	REQUIRE(5.0f == c1.getMax().y_);

	REQUIRE(0.5f == c1.getColor().r_);
	REQUIRE(0.5f == c1.getColor().g_);
	REQUIRE(0.5f == c1.getColor().b_);

}


/*

TEST CASES for Rectangle Circumference

*/


TEST_CASE("describe_circumference_rectangle", "[Rectangle]")
{
	Rectangle c1
	{
		Vec2{1.0f,2.0f},
		Vec2{4.0f,5.0f},
		Color{0.5f,0.5f,0.5f}
	};
	
	REQUIRE(12.0f == Approx(c1.circumference()));
}

/*

TEST CASES for Rectangle is point inside

*/


TEST_CASE("describe_is_inside_rectangle", "[Rectangle]")
{
	Rectangle square
	{
		Vec2 {20.0f,200.0f}, 
        Vec2 {200.0f,400.0f}, 
        Color {1.0f, 0.0f, 0.0f}
    };

    Vec2 point1 {100,300};
    Vec2 point2 {0,0};
	
	REQUIRE(true == square.is_inside(point1));
	REQUIRE(false == square.is_inside(point2));
}