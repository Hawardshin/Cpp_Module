
#include "Zombie.hpp"


int main(void)
{
	// Zombie zom;
	Zombie *zom(::newZombie("sss"));
	::randomChump("nae");
	delete zom;
}
