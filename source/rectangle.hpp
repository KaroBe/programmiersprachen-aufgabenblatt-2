//rectangle.hpp (programmiersprache-aufgabenblatt-2)

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "vec2.hpp"
#include "color.hpp"

class Rectangle
{
public:
	Rectangle (Vec2 const& min, Vec2 const& max, Color const& color);
	
	//Getter
	Vec2 const& getMin() const; //CONST RETÜRN???
	Vec2 const& getMax() const;
	Color const& getColor() const; //CONST RETÜRN???

private:
	Vec2 min_;
	Vec2 max_;
	Color color_;
};

#endif