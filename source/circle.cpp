//circle.cpp (programmiersprache-aufgabenblatt-2)

#include "circle.hpp"
#include "vec2.hpp"
#include "color.hpp"

//TO DO

Circle::Circle (Vec2 const& center, float radius, Color const& color):
	center_{center},
	radius_{radius},
	color_{color} {}

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