
#include "Zombie.hpp"

int main(void)
{
	int	zombie_num = 5;
	Zombie	a;
	a.set_name("S_Zom");
	a.announce();
	Zombie *zom(zombieHorde(zombie_num ,"H_THE_ZOMBIE"));
	for (int i=0; i < zombie_num;i++) zom[i].announce();
	delete [] zom;
}
