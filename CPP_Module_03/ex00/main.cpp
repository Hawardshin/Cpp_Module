# include "ClapTrap.hpp"

int main()
{
	std::cout << "\n------main start------\n\n";
	ClapTrap Tom("TOM");
	ClapTrap Jack("JACK");
	ClapTrap anonymous;
	Tom.attack(Jack.get_name());
	Tom.attack("JACK");
	Jack.takeDamage(Tom.get_attack_damage());
	Jack.takeDamage(5);
	Jack.beRepaired(5);
	std::cout << "\n------main end------\n\n";
	return (0);
}
