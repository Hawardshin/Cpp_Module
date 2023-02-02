
#include "Zombie.hpp"

Zombie:: Zombie(std::string name_):_name(name_){announce();}
Zombie::~Zombie(){std::cout << _name << ": delete\n";}

void	Zombie::announce(void){
	std::cout << _name << ": " <<"BraiiiiiiinnnzzzZ…" << std::endl;
}

void	Zombie::set_name(std::string name){_name = name;}

Zombie*	newZombie(std::string name){
	Zombie	*newzom = new Zombie(name);
	return (newzom);
}

void randomChump(std::string name){
	Zombie zombie(name);
}
