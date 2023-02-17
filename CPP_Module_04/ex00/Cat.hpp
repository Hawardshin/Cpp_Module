#pragma once

# include "Animal.hpp"
class Cat : public Animal
{
	private:

	public:
		Cat();
		Cat(const Cat& obj );
		~Cat();
		Cat& operator=(const Cat& obj );
		void makeSound() const;
};

