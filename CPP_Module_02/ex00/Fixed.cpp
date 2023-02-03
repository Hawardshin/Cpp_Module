#include "Fixed.hpp"

Fixed::Fixed() :fixed_value_store(0) {
	std::cout << "Default constructor called\n";
}
Fixed::Fixed(const Fixed& obj){
	std::cout << "Copy constructor called\n";
	*this = obj;
}
Fixed& Fixed::operator=(const Fixed& obj){
	std::cout << "Copy assignment operator called\n";
	fixed_value_store = obj.getRawBits();
	return (*this);
}
Fixed::~Fixed(){
	std::cout << "Destructor called\n";
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
