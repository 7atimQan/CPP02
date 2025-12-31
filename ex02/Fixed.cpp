#include "Fixed.hpp"
#include <math.h>

const int	Fixed::fractionalBits = 8;

Fixed::Fixed() : rawBits(0) {
	// std::cout << "Default contructor called" << std::endl;
}

Fixed::Fixed(const int rawBits) {
	// std::cout << "Int Contructor called" << std::endl;
	this->rawBits = rawBits << fractionalBits;
}

Fixed::Fixed(const float f) {
	// std::cout << "Float Contructor called" << std::endl; 
	rawBits = roundf(f * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &f) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed &Fixed::operator=(const Fixed &f) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f) {
		rawBits = f.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}



int	Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return rawBits;
}

void	Fixed::setRawBits(int const raw) {
	rawBits = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->getRawBits() / (float)(1 << fractionalBits));
}

int		Fixed::toInt(void) const {
	return this->getRawBits() >> fractionalBits;
}

std::ostream	&operator<<(std::ostream &output, Fixed const &fixed) {
	output << fixed.toFloat();
	return output;
}

//Comparison operators
bool	Fixed::operator>(const Fixed &f) const {
	return (this->getRawBits() > f.getRawBits());
}

bool	Fixed::operator>=(const Fixed &f) const {
	return (this->getRawBits() >= f.getRawBits());
}

bool	Fixed::operator<(const Fixed &f) const {
	return (this->getRawBits() < f.getRawBits());
}

bool	Fixed::operator<=(const Fixed &f) const {
	return (this->getRawBits() <= f.getRawBits());
}

bool	Fixed::operator==(const Fixed &f) const {
	return (this->getRawBits() == f.getRawBits());
}

bool	Fixed::operator!=(const Fixed &f) const {
	return (this->getRawBits() != f.getRawBits());
}


//Arithmetic operators
Fixed	&Fixed::operator+(const Fixed &fixed) {
	rawBits+= fixed.getRawBits();
	return (*this);
}

Fixed	&Fixed::operator-(const Fixed &fixed) {
	rawBits-= fixed.getRawBits();
	return (*this);
}

Fixed	&Fixed::operator*(const Fixed &fixed) {
	rawBits*= fixed.getRawBits() / (1 << fractionalBits);
	return (*this);
}

Fixed	const &Fixed::operator/(const Fixed &fixed) {
	rawBits = (this->getRawBits() / (1 << fractionalBits)) / fixed.getRawBits();
}

//overloaded min and max
Fixed&	Fixed::min(Fixed &f1, Fixed &f2) {
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::min(const Fixed &f1, const Fixed &f2) {
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed&	Fixed::max(Fixed &f1, Fixed &f2) {
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::max(const Fixed &f1, const Fixed &f2) {
	if (f1 > f2)
		return (f1);
	return (f2);
}

//Increment / Decrement
Fixed Fixed::operator++(int) {
	Fixed temp(*this);

	rawBits++;
	return (temp);
}

Fixed& Fixed::operator++() {
	rawBits++;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);

	rawBits--;
	return (temp);
}

Fixed& Fixed::operator--() {
	rawBits--;
	return (*this);
}