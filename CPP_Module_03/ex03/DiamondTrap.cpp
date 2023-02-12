#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :ClapTrap(), FragTrap(), ScavTrap()
{
	name="anonymous_clap_name";
	Hit_points = 100;
	Energy_points = 50;
	Attack_damage = 30;
	std::cout <<"[DiamondTrap Default constructor called]\n" <<"You make " << name << "\n\n";
}

DiamondTrap::DiamondTrap(std::string name) :  ClapTrap(name),FragTrap(),ScavTrap(), name(ClapTrap::name+"_clap_name")
{
	Hit_points = 100;
	Energy_points = 50;
	Attack_damage = 30;
	std::cout <<"[DiamondTrap parameter constructor called]\n" <<"You make " << DiamondTrap::name << "\n\n";
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
	<< "Clap name : " << ClapTrap::name << "\n\n";
}

void DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}
