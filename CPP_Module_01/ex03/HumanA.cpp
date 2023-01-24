#include "HumanA.hpp"

void	HumanA::attack(void){
	std::cout << name <<  " attacks with their " << weapon.getType() << "\n";
}

HumanA::HumanA(std::string s, Weapon &w)
{
	name = s;
	weapon = w;
}
