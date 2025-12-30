#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private :
		int					rawBits;
		static const int	fractionalBits;

	public :
		Fixed();
		Fixed(const int rawBits);
		Fixed(const float f);
		Fixed(const Fixed &f);
		Fixed &operator=(const Fixed &f);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &output,Fixed const &fixed);

#endif