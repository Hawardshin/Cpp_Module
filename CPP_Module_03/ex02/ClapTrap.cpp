
# include "ClapTrap.hpp"

ClapTrap:: ClapTrap() : name("anonymous"),Hit_points(10),Energy_points(10),Attack_damage(0){
	std::cout <<"[ClapTrap Default constructor called]\n" <<"You make " << name << "\n\n";
}

ClapTrap:: ClapTrap(std::string name) : name(name),Hit_points(10),Energy_points(10),Attack_damage(0){
	std::cout << "[ClapTrap parameter constructor called]\n" <<"You make " << name << "\n\n";
}

ClapTrap:: ClapTrap(std::string name,unsigned int Hit_points, unsigned int Energy_points, int Attack_damage)
:name(name),Hit_points(Hit_points),Energy_points(Energy_points),Attack_damage(Attack_damage){
	std::cout << "[ClapTrap Constructor with all attributes called]\n\n";
}

ClapTrap:: ClapTrap(const ClapTrap& obj){
	std::cout<< "[ClapTrap Copy constructor called]\n" << "You make " << obj.name << "\n\n";
	*this = obj;
}

ClapTrap:: ~ClapTrap(){
	std::cout<< "[ClapTrap Destructor called]\n" << "extinguish " << name << "\n\n";
}

ClapTrap& ClapTrap:: operator=(const ClapTrap& obj){
	std::cout << "[ClapTrap Copy assignment operator called]\n";
	name = obj.name;
	Hit_points = obj.Hit_points;
	Energy_points = obj.Energy_points;
	Attack_damage = obj.Attack_damage;
	return (*this);
}

void ClapTrap:: takeDamage(unsigned int amount){
	if (Hit_points <= amount)
		Hit_points = 0;
	else
		Hit_points -= amount;
	std::cout<<"ClapTrap "<< name <<" takeDamage "<< amount<<" points of damage!\n"\
	<<"So left Hit_point is " << Hit_points <<"\n\n";
}

void ClapTrap:: attack(const std::string& target){
	if (use_energy_points()){
		std::cout<<"ClapTrap "<< name <<" attacks "<< target<<", causing "<< Attack_damage<<" points of damage!\n\n";
	}
}

void ClapTrap:: beRepaired(unsigned int amount){
	if (use_energy_points()){
		Hit_points += amount;
		if (Hit_points > 10)
			Hit_points = 10;
		std::cout<<"ClapTrap "<< name <<" beRepaired "<<amount << " points!\n" \
		<<"So left Hit_point is " << Hit_points <<"\n\n";
	}
}

bool ClapTrap:: use_energy_points(){
	if (Hit_points > 10)
		Hit_points = 10;
	if (Energy_points > 10)
		Energy_points = 10;
	if (Hit_points == 0 || Energy_points == 0){
		std::cout<< "[ClapTrap can't do anything]\nif it has no hit points or energy points left.\n\n" ;
		return (false);
	}
	--Energy_points;
	return (true);
}

std::string ClapTrap:: get_name() const{return (name);}
unsigned int ClapTrap::get_attack_damage()const {return (Attack_damage);}
