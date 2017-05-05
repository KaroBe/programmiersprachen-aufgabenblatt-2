//color.cpp (programmiersprache-aufgabenblatt-2)

#include "rectangle.hpp"
#include "vec2.hpp"
#include "color.hpp"

//Constructor
Rectangle::Rectangle (Vec2 const& min, Vec2 const& max, Color const& color):
	min_{min},
	max_{max},
	color_{color} {}

//Getter
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


//Circumference
float Rectangle::circumference() const
{
	return 	(2.0f * (max_.x_ - min_.x_)) +
			(2.0f * (max_.y_ - min_.y_));
} //const, da "inspector"