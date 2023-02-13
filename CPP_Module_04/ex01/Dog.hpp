#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal{
	private :
		Brain *BrainPtr;

	public :
		Dog();
		Dog(const Dog& obj );
		~Dog();
		Dog& operator=(const Dog& obj );
		void makeSound() const;
};
