
#include "Zombie.hpp"

void	Zombie::set_name(std::string s){name = s;}

void	Zombie::announce(void){
	std::cout << name << ": " <<"BraiiiiiiinnnzzzZ…" << std::endl;
}

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombie_horde = new Zombie[N];
	for (int i=0; i<N;i++) zombie_horde[i].set_name(name);
	return (zombie_horde);
}
