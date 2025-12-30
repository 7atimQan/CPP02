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
		Fixed(int rawBits);
		Fixed(const Fixed &f);
		Fixed &operator=(const Fixed &f);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif