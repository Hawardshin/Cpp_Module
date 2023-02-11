# include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout <<"[ScavTrap Default constructor called]\n" <<"You make " << name << "\n\n";
	Hit_points = 100;
	Energy_points = 50;
	Attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) :ClapTrap(name) {
	std::cout <<"[ScavTrap parameter constructor called]\n" <<"You make " << name << "\n\n";
	Hit_points = 100;
	Energy_points = 50;
	Attack_damage = 20;
}
//this is need to understand
ScavTrap::ScavTrap(const ScavTrap &obj) :ClapTrap()  {
	std::cout<< "[ScavTrap Copy constructor called]\n" << "You make " << obj.name << "\n\n";
	*this = obj;
}

ScavTrap::~ScavTrap() {
	std::cout<< "[ScavTrap Destructor called]\n" << "extinguish " << name << "\n\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj){
	std::cout << "[ScavTrap Copy assignment operator called]\n";
	name = obj.name;
	Hit_points = obj.Hit_points;
	Energy_points = obj.Energy_points;
	Attack_damage = obj.Attack_damage;
	return (*this);
}

void ScavTrap::guardGate(){
	std::cout << "[!!ScavTrap Gate Keeper mode!!]\n\n";
}

void ScavTrap::attack(const std::string& target){
	if (use_energy_points()){
		std::cout<<"ScavTrap "<< name <<" attacks "<< target<<", causing "<< Attack_damage<<" points of damage!\n\n";
		// target.takeDamage(Attack_damage);
	}
}
