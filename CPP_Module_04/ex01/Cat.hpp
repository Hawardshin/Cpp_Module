#pragma once

# include "Animal.hpp"
# include "Brain.hpp"
class Cat : public Animal
{
	private:
		Brain* Brainptr;
	public:
		Cat();
		Cat(const Cat& obj );
		~Cat();
		Cat& operator=(const Cat& obj );
		void makeSound() const;
};

