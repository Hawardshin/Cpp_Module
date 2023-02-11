# include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("anonymous",100,100,30) {
	std::cout <<"[FragTrap Default constructor called]\n" <<"You make " << name << "\n\n";
}

FragTrap::FragTrap(std::string name) :ClapTrap(name,100,100,30){
	std::cout <<"[FragTrap parameter constructor called]\n" <<"You make " << name << "\n\n";
}

FragTrap::FragTrap(const FragTrap &obj) :ClapTrap(obj.name,obj.Hit_points,obj.Energy_points,obj.Attack_damage)  {
	std::cout<< "[FragTrap Copy constructor called]\n" << "You make " << obj.name << "\n\n";
	*this = obj;
}

FragTrap::~FragTrap() {
	std::cout<< "[FragTrap Destructor called]\n" << "extinguish " << name << "\n\n";
}

FragTrap& FragTrap::operator=(const FragTrap& obj){
	std::cout << "[FragTrap Copy assignment operator called]\n";
	name = obj.name;
	Hit_points = obj.Hit_points;
	Energy_points = obj.Energy_points;
	Attack_damage = obj.Attack_damage;
	return (*this);
}

void FragTrap::highFivesGuys(){
	std::cout << "[!!highFivesGuys!!]\n\n";
}

void FragTrap::attack(const std::string& target){
	if (use_energy_points()){
		std::cout<<"FragTrap "<< name <<" attacks "<< target<<", causing "<< Attack_damage<<" points of damage!\n\n";
	}
}
