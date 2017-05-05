//circle.cpp (programmiersprache-aufgabenblatt-2)

#include "circle.hpp"
#include "vec2.hpp"
#include "color.hpp"
#include <cmath>

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