#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>


class Fixed{
	private :
		int					fixed_value_store;
		static const int	fractional_bits_store = 8;//always 8

	public :	//Orthodox Canonical Form
				Fixed();
				explicit Fixed(int);
				explicit Fixed(float);
				Fixed(const Fixed& obj);
				~Fixed();
				/* member fuction */
				float toFloat(void) const; //converts the fixed-point value to a floating-point value.
				int toInt(void) const; //converts the fixed-point value to an integer value.
				int getRawBits( void ) const;
				void setRawBits( int const raw );

				Fixed& operator=(const Fixed& obj);

				/* comparison operators overloading*/
				bool operator>(const Fixed& obj);
				bool operator>=(const Fixed& obj);
				bool operator<(const Fixed& obj);
				bool operator<=(const Fixed& obj);
				bool operator==(const Fixed& obj);
				bool operator!=(const Fixed& obj);

				/* Arithmetic operation overloading*/
				Fixed operator+(const Fixed& obj);
				Fixed operator-(const Fixed& obj);
				Fixed operator*(const Fixed& obj);
				Fixed operator/(const Fixed& obj);

				/*Argument x has no meaning.
				Simply put an int argument to distinguish between prefix and postfix on the compiler.*/

				Fixed& operator++(void); //++a
				Fixed& operator--(void);
				Fixed operator++(int);//a++
				Fixed operator--(int);

				//static member function
				static Fixed&		min(Fixed& a, Fixed& b);
				static const Fixed&	min(const Fixed& a, const Fixed& b);
				static Fixed&		max(Fixed& a, Fixed& b);
				static const Fixed&	max(const Fixed& a, const Fixed& b);

};

/*
In principle, all binary operators that do not return themselves,
such as +, -, *, and / as above,
should be declared as external functions.
but our subject doesn't allow friend keyword so I did it out of necessity.
*/
std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif
