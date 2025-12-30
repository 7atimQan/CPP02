#include "Fixed.hpp"

int main( void ) {
	Fixed a(246);
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() / pow(2, 8) << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}