#include "HumanB.hpp"

HumanB::HumanB(const std::string &name_){name = name_;}

void	HumanB::attack(void){
	std::cout << name <<  " attacks with their " << weapon.getType() << "\n";
}
