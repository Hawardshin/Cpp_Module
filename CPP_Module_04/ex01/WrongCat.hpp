#pragma once

#include "WrongAnimal.hpp"

class WrongCat :public WrongAnimal
{
private:

public:
	WrongCat();
	WrongCat(const WrongCat& obj );
	~WrongCat();
	WrongCat& operator=(const WrongCat& obj );
	void makeSound() const;
};
