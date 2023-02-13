#pragma once

# include <iostream>
# include <string>


class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	explicit WrongAnimal(std::string);
	WrongAnimal(const WrongAnimal& obj );
	virtual ~WrongAnimal();
	WrongAnimal& operator=(const WrongAnimal& obj );

	void makeSound() const;
	std::string getType() const;

};
