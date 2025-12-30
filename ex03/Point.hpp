#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point {
	private:
		const Fixed x;
		const Fixed	y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &p);
		Point &operator=(const Point &p);
		~Point();

		const Fixed	getX(void) const;
		const Fixed	getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif