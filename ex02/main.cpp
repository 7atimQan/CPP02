#include "Fixed.hpp"

// int main( void ) {
// 	Fixed a(19);
// 	Fixed b(19);

// 	for (int i = 0; i < 256; i++)
// 		b++;
// 	if (a > b)
// 		std::cout << "a is bigger : " << a + b << std::endl;
// 	else if (a != b)
// 		std::cout << "b is bigger : " << a + b << std::endl;
// 	else
// 		std::cout << "a equals b : " << a + b << std::endl;
// }

#include <iostream>
int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}