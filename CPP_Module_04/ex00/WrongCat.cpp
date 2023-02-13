#include "WrongCat.hpp"

WrongCat::WrongCat() :WrongAnimal("WrongCat"){
	std::cout <<"[WrongCat Default constructor called]\n" <<"You make " << type << "\n\n";
}

WrongCat::WrongCat(const WrongCat &obj) {
	std::cout <<"[WrongCat Copy constructor called]\n" <<"You make " << obj.type << "\n\n";
}

WrongCat::~WrongCat() {
	std::cout <<"[WrongCat Destructor called]\n" <<"extinguish " << type << "\n\n";
}

WrongCat& WrongCat::operator=(const WrongCat& obj){
	std::cout <<"[WrongCat Destructor called]\n" <<"extinguish " << type << "\n\n";
	type = obj.type;
	return (*this);
}

void WrongCat:: makeSound() const{
	std::cout << type << ": Meow, meow, meowwwwwww\n\n";
}
