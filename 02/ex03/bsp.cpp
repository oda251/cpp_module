#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Point AB = b - a;
	Point BP = point - b;
	Point BC = c - b;
	Point CP = point - c;
	Point CA = a - c;
	Point AP = point - a;

	Fixed c1 = AB.getX() * BP.getY() - AB.getY() * BP.getX();
	Fixed c2 = BC.getX() * CP.getY() - BC.getY() * CP.getX();
	Fixed c3 = CA.getX() * AP.getY() - CA.getY() * AP.getX();

	return (c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0);
}
