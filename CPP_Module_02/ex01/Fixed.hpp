#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>


class Fixed{
	private :
		int					fixed_value_store;
		static const int	fractional_bits_store = 8;//always 8

	public :	Fixed();
				Fixed(int);
				Fixed(float);
				Fixed(const Fixed& obj);
				Fixed& operator=(const Fixed& obj);
				~Fixed();

				float toFloat(void) const; //converts the fixed-point value to a floating-point value.
				int toInt(void) const; //converts the fixed-point value to an integer value.
				int getRawBits( void ) const; //
				void setRawBits( int const raw );
};
std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif
