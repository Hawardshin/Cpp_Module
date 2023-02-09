#include "Fixed.hpp"

Fixed::Fixed() :fixed_value_store(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int param){
	fixed_value_store = param << fractional_bits_store;
	std::cout << "Default constructor called\n";
}

// roundf to use for accuracy
Fixed::Fixed(float param){
	std::cout << "Default constructor called\n";
	fixed_value_store = roundf(param * (1 << fractional_bits_store));
}

Fixed::Fixed(const Fixed& obj){
	std::cout << "Copy constructor called\n";
	*this = obj;
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

float Fixed:: toFloat(void) const
{
	return (static_cast<float>(fixed_value_store) / (1 << fractional_bits_store));
}

int Fixed:: toInt(void) const
{
	return (fixed_value_store / (1 << fractional_bits_store));
}

int Fixed::getRawBits( void ) const
{
	std::cout <<"getRawBits member function called\n";
	return (fixed_value_store);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	fixed_value_store = raw;
}

Fixed& Fixed::operator=(const Fixed& obj){
	std::cout << "Copy assignment operator called\n";
	fixed_value_store = obj.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
