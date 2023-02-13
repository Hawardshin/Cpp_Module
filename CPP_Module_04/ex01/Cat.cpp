#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	Brainptr = new Brain();
	std::cout <<"[Cat Default constructor called]\n" <<"You make " << type << "\n\n";
}

Cat:: Cat(const Brain *Brainptr_) : Animal("Cat")
{
	Brainptr = new Brain(*Brainptr_);
	std::cout <<"[Cat with Brain parameter constructor called]\n\n";
}

Cat::Cat(const Cat &obj) {
	std::cout<< "[Cat Copy constructor called]\n" << "You make " << obj.type << "\n\n";
	*this = obj;
}

Cat::~Cat() {
	std::cout<< "[Cat Destructor called]\n" << "extinguish " << type << "\n\n";
	delete Brainptr;
}

Cat& Cat::operator=(const Cat& obj){
	std::cout << "[Cat Copy assignment operator called]\n";
	type = obj.type;
	Brainptr = new Brain();
	return (*this);
}

void Cat::makeSound() const{
	std::cout << type << ": Meow, meow, meowwwwwww\n\n";
}
