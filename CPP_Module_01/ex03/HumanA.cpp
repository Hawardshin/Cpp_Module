#include "HumanA.hpp"

HumanA::HumanA(const std::string &_name,const Weapon &_weapon)
{
	name = _name;
	weapon = _weapon;
}

void	HumanA::attack(void){
	std::cout << name <<  " attacks with their " << weapon.getType() << "\n";
}

