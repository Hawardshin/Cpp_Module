#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
	name="anonymous_clap_name";
	std::cout <<"[DiamondTrap Default constructor called]\n" <<"You make " << name << "\n\n";
}

DiamondTrap::DiamondTrap(std::string name) :  FragTrap(name),ScavTrap(name), name(ClapTrap::name+"_clap_name")
{
	std::cout <<"[DiamondTrap parameter constructor called]\n" <<"You make " << name << "\n\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj){
	std::cout << "[DiamondTrap Copy assignment operator called]\n";
	name = obj.name;
	Hit_points = obj.FragTrap::Hit_points;
	Energy_points = obj.ScavTrap::Energy_points;
	Attack_damage = obj.FragTrap::Attack_damage;
	return (*this);
}

DiamondTrap::~DiamondTrap(){
	std::cout<< "[DiamondTrap Destructor called]\n" << "extinguish " << name << "\n\n";
}

void DiamondTrap::whoAmI(){
	std::cout << "Dia name : " << name << "\n"
	<< "Clap name" << ClapTrap::name;
}

void DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}
