
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
int main()
{
	{
		std::cout << "\n-----------------test1----------------\n\n";
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
		std::cout << "\n-----------------test1-end------------\n\n";
	}
	{
		std::cout << "\n-----------------test2----------------\n\n";
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* C = new WrongCat();
		std::cout << C->getType() << " " << std::endl;
		C->makeSound();
		meta->makeSound();
		delete meta;
		delete C;
		std::cout << "\n-----------------test2-end------------\n\n";
	}
	system("leaks Animal");
	return 0;
}
