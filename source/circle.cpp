//circle.cpp (programmiersprache-aufgabenblatt-2)

#include "circle.hpp"

//Constructor
Circle::Circle (Vec2 const& center, float radius, Color const& color):
	center_{center},
	radius_{radius},
	color_{color} {}

//Getter
Vec2 const& Circle::getCenter() const //CONST RETÜRN???
{
	return center_;
}

float Circle::getRadius() const
{
	return radius_;
}

Color const& Circle::getColor() const //CONST RETÜRN???
{
	return color_;
}

//Circumference
float Circle::circumference() const
{
	return (float)(2.0f * M_PI * radius_);
}

//draw
void Circle::draw(Window const& window)
{
	draw(window, color_);
}

//draw with explicit color
void Circle::draw(Window const& window, Color const& color)
{
	//2PI = Vollwinkel -> * i/360 = 360 Segmente des Kreises
	//Rotationsmatrix berechnen
	// x = Anz Segmente
	float x = 48.0f;
	Mat2 rotMat = make_rotation_mat2 ((float)(2.0f * M_PI / x));
	
	//Startpunkt
	Vec2 p0{radius_, 0.0};		

	for (int i = 1; i <= x; i++){
		//Endpunkt berechnen
		Vec2 p1 = rotMat*p0;
		
		//Linie zeichnen dazwischen
		window.draw_line
			(
				center_.x_ + p0.x_,
				center_.y_ + p0.y_,
				center_.x_ + p1.x_, 
				center_.y_ + p1.y_, 
				color.r_, color.g_, color.b_
			);

		//Startpunkt weiter drehen
		p0 = rotMat*p0;
	}
}

//is inside
bool Circle::is_inside(Vec2 point)
{
	float distance = sqrt(
						pow(x_ - point.x_,2.0f)
						+ pow(y_ - point.y_,2.0f)
					);

	if(distance < radius_)
	{
		return true;
	}
	else
	{
		return false;
	}
}