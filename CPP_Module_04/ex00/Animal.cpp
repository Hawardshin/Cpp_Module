
#include "Animal.hpp"

Animal:: Animal():type("Animal"){
	std::cout <<"[Animal Default constructor called]\n\n";
}

Animal:: Animal(std::string type_) : type(type_){
	std::cout << "[Animal parameter constructor called]\n" <<"You make " << type << "\n\n";
}

Animal::Animal(const Animal &obj){
	std::cout<< "[Animal Copy constructor called]\n" << "You make " << obj.type << "\n\n";
	*this = obj;
}

Animal& Animal::operator=(const Animal & obj){
	std::cout << "[Animal Copy assignment operator called]\n";
	type = obj.type;
	return (*this);
}

Animal:: ~Animal(){
	std::cout<< "[Animal Destructor called]\n" << "extinguish " << type << "\n\n";
}

void Animal:: makeSound() const{
	std::cout << "[Animal CANNOT make sound Yet]\n\n";
}

std::string Animal:: getType() const{
	return (type);
}
