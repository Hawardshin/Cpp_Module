#pragma once
#include "Animal.hpp"

class Dog : public Animal{
	private :

	public :
		Dog();
		Dog(const Dog& obj );
		~Dog();
		Dog& operator=(const Dog& obj );
		void makeSound() const;
};
