#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
	private :
		Brain *BrainPtr;

	public :
		Dog();
		explicit Dog(const Brain *Brainptr_);
		Dog(const Dog& obj );
		~Dog();

		Dog& operator=(const Dog& obj );
		void makeSound() const;

		//for test
		void	see_brain();
};
