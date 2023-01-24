
#include "Zombie.hpp"

void	Zombie::announce(void){
	std::cout << name << ": " <<"BraiiiiiiinnnzzzZ…" << std::endl;
}

void	Zombie::set_name(std::string s){name = s;}

Zombie*	newZombie(std::string s){
	Zombie	*newzom = new Zombie;
	newzom->set_name(s);
	newzom->announce();
	return (newzom);
}

void randomChump(std::string name){
	Zombie zombie(name);
	zombie.announce();
}
