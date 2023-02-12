# include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("anonymous",100,50,20) {
	std::cout <<"[ScavTrap Default constructor called]\n" <<"You make " << name << "\n\n";
}

ScavTrap::ScavTrap(std::string name) :ClapTrap(name,100,50,20){
	std::cout <<"[ScavTrap parameter constructor called]\n" <<"You make " << name << "\n\n";
}

ScavTrap::ScavTrap(const ScavTrap &obj) :ClapTrap(obj.name,obj.Hit_points,obj.Energy_points,obj.Attack_damage)  {
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
	}
}
