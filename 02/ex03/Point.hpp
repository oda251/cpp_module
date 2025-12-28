#pragma once
#include "Fixed.hpp"

class Point {
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Fixed x, const Fixed y);
		Point(const Point &src);
		Point& operator=(const Point &src);
		Point operator-(const Point &src) const;
		~Point();
		Fixed getX(void) const;
		Fixed getY(void) const;
};
