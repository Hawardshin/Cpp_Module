#pragma once

#include <string>
#include <iostream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	explicit Brain(std::string *ideas_);
	Brain(const Brain& obj );
	~Brain();
	Brain& operator=(const Brain& obj );
};
