#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>


class Fixed{
	private :
		int					fixed_value_store;
		static const int	fractional_bits_store = 8;//always 8


	public :	Fixed();
				Fixed(const Fixed& obj);
				Fixed& operator=(const Fixed& obj);
				~Fixed();

				int getRawBits( void ) const;
				void setRawBits( int const raw );
};

#endif
