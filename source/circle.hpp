//circle.hpp (programmiersprache-aufgabenblatt-2)

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"
#include "color.hpp"

class Circle
{
public:
	Circle (Vec2 const& center, float radius, Color const& color);
	
	//Getter
	Vec2 const& getCenter() const; //CONST RETÜRN???
	float getRadius() const;
	Color const& getColor() const; //CONST RETÜRN???

	//Circumference
	float circumference() const; //const, da "inspector"

private:
	Vec2 center_;
	float radius_;
	Color color_;
};

#endif