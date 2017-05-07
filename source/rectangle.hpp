//rectangle.hpp (programmiersprache-aufgabenblatt-2)

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

#include "rectangle.hpp"
#include "vec2.hpp"
#include "color.hpp"

class Rectangle
{
public:
	Rectangle (Vec2 const& min, Vec2 const& max, Color const& color);
	
	//Getter
	Vec2 const& getMin() const;
	Vec2 const& getMax() const;
	Color const& getColor() const;

	//Circumference
	float circumference() const;

	//Draw
	void draw(Window const& window);
	void draw(Window const& window, Color const& color);

	//is inside
	bool is_inside(Vec2 point);

private:
	Vec2 min_;
	Vec2 max_;
	Color color_;
};

#endif