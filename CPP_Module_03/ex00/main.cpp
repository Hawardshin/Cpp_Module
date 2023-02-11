# include "ClapTrap.hpp"

/* other main*/
// int main()
// {
// 	std::cout << "\n------main start------\n\n";
// 	ClapTrap Tom("TOM");
// 	ClapTrap Jack("JACK");
// 	ClapTrap anonymous;
// 	Tom.attack(Jack.get_name());
// 	Tom.attack("JACK");
// 	Jack.takeDamage(5);
// 	Jack.beRepaired(3);//1
// 	Jack.attack("Tom");//2
// 	Tom.takeDamage(100);
// 	// energy is only
// 	for (int i=0;i < 10;i++){
// 		Jack.beRepaired(1);
// 	}
// 	Tom.beRepaired(10);
// 	std::cout << "\n------main end------\n\n";
// 	return (0);
// }

int main()
{
	std::cout << "\n------main start------\n\n";
	ClapTrap Jack("JACK");
	Jack.attack("TOM");
	Jack.takeDamage(5);
	Jack.beRepaired(5);
	std::cout << "\n------main end------\n\n";
	return (0);
}
