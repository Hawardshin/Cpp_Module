#pragma once

#include "WrongAnimal.hpp"

class WrongCat :public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat& obj );
	~WrongCat();
	WrongCat& operator=(const WrongCat& obj );
	void makeSound() const;
};
