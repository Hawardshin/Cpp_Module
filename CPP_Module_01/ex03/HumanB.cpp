#include "HumanB.hpp"

HumanB::HumanB(const std::string &name_): name(name_),weapon(NULL){}

void	HumanB::setWeapon(Weapon &weapon_){ weapon = &weapon_;}

void	HumanB::attack(void){
	if (weapon == NULL) {
		std::cout << "Weapon is not exist" << std::endl;
		return;
	}
	std::cout << name <<  " attacks with their " << weapon->getType() << "\n";
}
