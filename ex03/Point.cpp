#include "Point.hpp"

Point::Point() : x(0), y(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float _x, const float _y) : x(Fixed(_x)), y(Fixed(_y)) {
	// std::cout << "Parametric constructor called" << std::endl;
}

Point::Point(const Point &p) : x(p.getX()), y(p.getY()) {
	// std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &p) {
	// std::cout << "Copy assignment operator called" << std::endl;
	(void)p;
	return (*this);
}

Point::~Point() {
	// std::cout << "Destructor called" << std::endl;
}

const Fixed	Point::getX(void) const{
	return this->x;
}

const Fixed	Point::getY(void) const{
	return this->y;
}