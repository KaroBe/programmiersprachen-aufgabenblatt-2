//mat2.hpp (programmiersprache-aufgabenblatt-2)

#ifndef MAT2_HPP
#define MAT2_HPP

struct Mat2
{
public:
	Mat2();
	Mat2(float a, float b, float c, float d);

	// Matrix der Form:
	// ( v11 v12 )
	// ( v21 v22 )
	
	float v11_;
	float v12_;
	
	float v21_;
	float v22_;

	Mat2& operator *= (Mat2 const& m);
};

Mat2 operator * (Mat2 const& m, Mat2 const & n);

#endif