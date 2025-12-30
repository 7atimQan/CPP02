
#include "Fixed.hpp"

const int	Fixed::n = 8;

Fixed::Fixed() : value(0) {
	std::cout << "Default contructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int Contructor called" << std::endl;
	this->value = value << n;
}

Fixed::Fixed(const float f) {
	std::cout << "Float Contructor called" << std::endl; 
	value = f * pow(2, n);
}

Fixed::Fixed(const Fixed &f) {
	std::cout << "Copy constructor called" << std::endl;
	value = f.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &f) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f) {
		value = f.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}



int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void	Fixed::setRawBits(int const raw) {
	value = raw;
}

float	Fixed::toFloat(void) const {
	return roundf(this->getRawBits() / pow(2, (const int)n));
}

int		Fixed::toInt(void) const {
	return this->getRawBits() >> n;
}

std::ostream	&operator<<(std::ostream &output,Fixed const fixed) {
	output << fixed.toFloat();
	return output;
}