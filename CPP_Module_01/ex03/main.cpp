#include "HumanA.hpp"
#include "HumanB.hpp"

//weapon포인터를 언제 사용하는게 좋은가에 대한 고민하라고 한다.
int main() {
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club"); bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club"); jim.attack();
	}
	return 0;
}
