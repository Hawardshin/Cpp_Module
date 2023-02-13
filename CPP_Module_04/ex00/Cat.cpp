#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout <<"[Cat Default constructor called]\n" <<"You make " << type << "\n\n";
}

Cat::Cat(const Cat &obj) {
	std::cout<< "[Cat Copy constructor called]\n" << "You make " << obj.type << "\n\n";
	*this = obj;
}

Cat::~Cat() {
	std::cout<< "[Cat Destructor called]\n" << "extinguish " << type << "\n\n";
}

Cat& Cat::operator=(const Cat& obj){
	std::cout << "[Cat Copy assignment operator called]\n";
	type = obj.type;
	return (*this);
}

void Cat::makeSound() const{
	std::cout << type << ": Meow, meow, meowwwwwww\n\n";
}
