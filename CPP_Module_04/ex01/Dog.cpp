#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	BrainPtr = new Brain();
	std::cout <<"[Dog Default constructor called]\n" <<"You make " << type << "\n\n";
}

Dog::Dog(const Dog &obj) {
	std::cout<< "[Dog Copy constructor called]\n" << "You make " << obj.type << "\n\n";
	*this = obj;
}

Dog::~Dog() {
	std::cout<< "[Dog Destructor called]\n" << "extinguish " << type << "\n\n";
	delete BrainPtr;
}

Dog& Dog::operator=(const Dog& obj){
	std::cout << "[Dog Copy assignment operator called]\n";
	type = obj.type;
	return (*this);
}

void Dog::makeSound() const{
	std::cout << type << ": Woof, woof, woof woof\n\n";
}
