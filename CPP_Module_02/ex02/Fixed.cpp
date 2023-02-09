#include "Fixed.hpp"

std::ostream&	operator<<(std::ostream& os, const Fixed& obj){
	os << obj.toFloat();
	return (os);
}

/* Orthodox Canonical Form */
Fixed::Fixed() :fixed_value_store(0) {
}

Fixed::Fixed(int param){
	fixed_value_store = param << fractional_bits_store;
}

// roundf to use for accuracy
Fixed::Fixed(float param){
	fixed_value_store = roundf(param * (1 << fractional_bits_store));
}

Fixed::Fixed(const Fixed& obj){
	*this = obj;
}

Fixed::~Fixed(){
}

/* member fuction */
float Fixed:: toFloat(void) const{
	return (static_cast<float>(fixed_value_store) / (1 << fractional_bits_store));
}

int Fixed:: toInt(void) const{
	return (fixed_value_store / (1 << fractional_bits_store));
}

int Fixed::getRawBits( void ) const{
	return (fixed_value_store);
}

void Fixed::setRawBits( int const raw ){
	fixed_value_store = raw;
}

Fixed& Fixed::operator=(const Fixed& obj){
	fixed_value_store = obj.getRawBits();
	return (*this);
}

/* comparison operators overloading */

bool Fixed::operator>(const Fixed& obj){
	return (fixed_value_store > obj.fixed_value_store);
}

bool Fixed::operator>=(const Fixed& obj){
	return (fixed_value_store >= obj.fixed_value_store);
}

bool Fixed::operator<(const Fixed& obj){
	return (fixed_value_store < obj.fixed_value_store);
}

bool Fixed::operator<=(const Fixed& obj){
	return (fixed_value_store <= obj.fixed_value_store);
}

bool Fixed::operator==(const Fixed& obj){
	return (fixed_value_store == obj.fixed_value_store);
}

bool Fixed::operator!=(const Fixed& obj){
	return (fixed_value_store != obj.fixed_value_store);
}

/*Arithmetic operation overloading*/

Fixed Fixed::operator+(const Fixed& obj){
	Fixed temp;//why it work? to private init
	temp.fixed_value_store = fixed_value_store + obj.fixed_value_store;
 	return temp;
}

Fixed Fixed::operator-(const Fixed& obj){
	Fixed temp;
	temp.fixed_value_store = fixed_value_store - obj.fixed_value_store;
 	return temp;
}

Fixed Fixed::operator*(const Fixed& obj){
	Fixed temp;
	float ret(toFloat() * obj.toFloat());
	temp.fixed_value_store = roundf(ret * (1 << fractional_bits_store));
 	return temp;
}

Fixed Fixed::operator/(const Fixed& obj){
	Fixed temp;
	float ret(toFloat() / obj.toFloat());
	temp.fixed_value_store = roundf(ret * (1 << fractional_bits_store));
 	return temp;
}

/* Prefix post operator overload */

Fixed&	Fixed::operator++(void){ //pre (++a)
	++fixed_value_store;
	return *this;
}

Fixed&	Fixed::operator--(void){
	--fixed_value_store;
	return *this;
}

Fixed	Fixed::operator++(int){// post (a++)
	Fixed temp(*this);
	++fixed_value_store;
	return (temp);
}

Fixed	Fixed::operator--(int){
	Fixed temp(*this);
	--fixed_value_store;
	return (temp);
}

/* static member function */

Fixed&	Fixed::min(Fixed& a, Fixed& b){
	return (a.fixed_value_store < b.fixed_value_store ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	return (a.fixed_value_store < b.fixed_value_store ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
	return (a.fixed_value_store > b.fixed_value_store ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	return (a.fixed_value_store > b.fixed_value_store ? a : b);
}
