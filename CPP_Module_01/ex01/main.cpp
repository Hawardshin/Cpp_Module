
#include "Zombie.hpp"

int main(void)
{
	int	zombie_num = 5;
	Zombie *zom(zombieHorde(zombie_num ,"THE_ZOMBIE"));
	for (int i=0; i < zombie_num;i++) zom[i].announce();
	delete [] zom;
}
