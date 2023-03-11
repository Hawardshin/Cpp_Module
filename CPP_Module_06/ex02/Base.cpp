#include "Base.hpp"

Base::~Base()
{
	std::cout << "Base destructor called..\n";
}

// It randomly instanciates A, B or C and returns the instance as a Base pointer.
// Feel free to use anything you like for the random choice implementation.
