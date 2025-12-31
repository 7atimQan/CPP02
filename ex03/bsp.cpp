#include "Point.hpp"

Fixed area(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3)
{
	return abs((x1.getRawBits() * (y2.getRawBits() - y3.getRawBits())
          + x2.getRawBits() * (y3.getRawBits() - y1.getRawBits())
          + x3.getRawBits() * (y1.getRawBits() - y2.getRawBits())) / 2);
}
 

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed A = area (a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());

	Fixed A1 = area (point.getX(), point.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	Fixed A2 = area (a.getX(), a.getY(), point.getX(), point.getY(), c.getX(), c.getY());
	Fixed A3 = area (point.getX(), point.getY(), a.getX(), a.getY(), b.getX(), b.getY());

	return (A1 != 0 && A2 != 0 && A3 != 0 && A == A1 + A2 + A3);
}
