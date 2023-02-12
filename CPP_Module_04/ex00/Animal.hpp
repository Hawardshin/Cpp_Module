#pragma once
# include <string>
# include <iostream>

class Animal{

	protected :
		std::string type;

	public :
		Animal();
		explicit Animal(std::string type_);
		Animal(const Animal &obj);
		Animal &operator=(const Animal & obj);
		virtual ~Animal();

		virtual void makeSound();
		virtual void getType();

};
