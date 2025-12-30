#include "Fixed.hpp"
#include <math.h>

const int	Fixed::fractionalBits = 8;

Fixed::Fixed() : rawBits(0) {
	std::cout << "Default contructor called" << std::endl;
}

Fixed::Fixed(const int rawBits) {
	std::cout << "Int Contructor called" << std::endl;
	this->rawBits = rawBits << fractionalBits;
}

Fixed::Fixed(const float f) {
	std::cout << "Float Contructor called" << std::endl; 
	rawBits = roundf(f * pow(2, fractionalBits));
}

Fixed::Fixed(const Fixed &f) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed &Fixed::operator=(const Fixed &f) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f) {
		rawBits = f.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}



int	Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return rawBits;
}

void	Fixed::setRawBits(int const raw) {
	rawBits = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->getRawBits() / (float)pow(2, fractionalBits));
}

int		Fixed::toInt(void) const {
	return this->getRawBits() >> fractionalBits;
}

std::ostream	&operator<<(std::ostream &output,Fixed const &fixed) {
	output << fixed.toFloat();
	return output;
}