# include "ScavTrap.hpp"
int main()
{
	std::cout << "\n------main start------\n\n";
	{
		std::cout << "\n-----test1 for virtual fuction------\n\n";
		ScavTrap Scav("S1");
		ClapTrap Clap1("C1");
		ClapTrap &Clap2 = Scav; //virtual fuc attack
		Clap1.attack("MET");
		Clap2.attack("MOT");
		Scav.attack("TOM");
		std::cout << "\n------------test1 done--------------\n\n";
	}
	{
		std::cout << "\n-----test2 for virtual Destructor------\n\n";
		ClapTrap *Clap = new ScavTrap("HERO");
		Clap->attack("villain");
		delete Clap;
		std::cout << "\n------------test2 done--------------\n\n";
	}
	std::cout << "\n------main end------\n\n";
	return (0);
}


// int main()
// {
// 	std::cout << "\n------main start------\n\n";
// 	ScavTrap Scav("Scav");
// 	Scav.attack("TOM");
// 	Scav.takeDamage(5);
// 	Scav.beRepaired(5);
// 	Scav.guardGate();
// 	std::cout << "\n------main end------\n\n";
// 	return (0);
// }
