
#include "Zombie.hpp"

int main(void)
{
	Zombie *zom(::newZombie("sss"));
	::randomChump("nae");
	delete zom;
}
