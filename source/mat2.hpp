//mat2.hpp (programmiersprache-aufgabenblatt-2)

#ifndef MAT2_HPP
#define MAT2_HPP

#include "vec2.hpp"

struct Mat2
{
	Mat2();
	Mat2(float a, float b, float c, float d);

	// Matrix der Form:
	// ( v11 v12 )
	// ( v21 v22 )
	
	float v11_;
	float v12_;
	float v21_;
	float v22_;

	//Matrizenmultiplikation
	Mat2& operator *= (Mat2 const& m);

	//Determinante berechnen
	float det() const;
};

//Matrizenmultiplikation
Mat2 operator * (Mat2 const& m, Mat2 const & n);

//Matrix * Vektor
Vec2 operator *( Mat2 const & m , Vec2 const & v );
Vec2 operator *( Vec2 const & v , Mat2 const & m );

//Inverse berechnen
Mat2 inverse ( Mat2 const & m );

// Matrix transponieren
Mat2 transpose ( Mat2 const & m );

//Rotationsmatrix von Winkel in Bogenmaß
Mat2 make_rotation_mat2 ( float phi );

#endif