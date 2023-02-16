#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout <<"[WrongAnimal Default constructor called]\n" <<"You make " << type << "\n\n";
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout <<"[WrongAnimal parameter constructor called]\n" << "You make" << type << "\n\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
	std::cout <<"[WrongAnimal Copy constructor called]\n" <<"You make " << obj.type << "\n\n";
}

WrongAnimal::~WrongAnimal() {
	std::cout <<"[WrongAnimal Destructor called]\n" <<"extinguish " << type << "\n\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj){
	std::cout <<"[WrongAnimal Copy assignment operator called]\n\n";
	type = obj.type;
	return (*this);
}
void WrongAnimal::makeSound() const{
	std::cout << "[WrongAnimal CANNOT make sound Yet]\n\n";
}
std::string WrongAnimal::getType() const{
	return (type);
}
