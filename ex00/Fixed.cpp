#include "Fixed.hpp"

const int	fractionalBits = 8;

Fixed::Fixed() : rawBits(0) {
	std::cout << "Default contructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f) {
	std::cout << "Copy constructor called" << std::endl;
	rawBits = f.getRawBits();
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
	std::cout << "getRawBits member function called" << std::endl;
	return rawBits;
}

void	Fixed::setRawBits(int const raw) {
	rawBits = raw;
}