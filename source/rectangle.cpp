//color.cpp (programmiersprache-aufgabenblatt-2)

#include "rectangle.hpp"
#include "vec2.hpp"
#include "color.hpp"

Rectangle::Rectangle (Vec2 const& min, Vec2 const& max, Color const& color):
	min_{min},
	max_{max},
	color_{color} {}

Vec2 const& Rectangle::getMin() const
{
	return min_;
} //CONST RETÜRN???

Vec2 const& Rectangle::getMax() const
{
	return max_;
}

Color const& Rectangle::getColor() const
{
	return color_;
}