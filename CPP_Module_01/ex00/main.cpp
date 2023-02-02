
#include "Zombie.hpp"

int main(void)
{
	Zombie *a(::newZombie("H_ZOM"));
	Zombie b("S_ZOM");
	::randomChump("R_ZOM1");
	::randomChump("R_ZOM2");
	delete a;
}
