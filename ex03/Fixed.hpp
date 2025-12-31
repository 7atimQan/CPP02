#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <math.h>

class Fixed
{
	private :
		int					rawBits;
		static const int	fractionalBits;

	public :
		//orthodox canonical form
		Fixed();
		Fixed(const int rawBits);
		Fixed(const float f);
		Fixed(const Fixed &f);
		Fixed const &operator=(const Fixed &f);
		~Fixed();

		//get_set
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		//conversion
		float	toFloat(void) const;
		int		toInt(void) const;

		//comparison operators
		bool	operator>(const Fixed &f) const;
		bool	operator>=(const Fixed &f) const;
		bool	operator<(const Fixed &f) const;
		bool	operator<=(const Fixed &f) const;
		bool	operator==(const Fixed &f) const;
		bool	operator!=(const Fixed &f) const;

		//arithmetic operators
		Fixed	&operator+(const Fixed &f);
		Fixed	&operator-(const Fixed &f);
		Fixed	&operator*(const Fixed &f);
		Fixed	const &operator/(const Fixed &f);

		//increment / decrement
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		//overloaded min and max
		static 			Fixed&	min(Fixed &f1, Fixed &f2);
		static const	Fixed&	min(const Fixed &f1, const Fixed &f2);
		static 			Fixed&	max(Fixed &f1, Fixed &f2);
		static const	Fixed&	max(const Fixed &f1, const Fixed &f2);
};

std::ostream	&operator<<(std::ostream &output,Fixed const &fixed);

#endif