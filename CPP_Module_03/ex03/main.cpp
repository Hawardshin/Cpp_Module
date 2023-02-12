# include "DiamondTrap.hpp"

int main()
{
	std::cout << "\n------main start------\n\n";
	{
		std::cout << "\n-----test1 for virtual fuction------\n\n";
		DiamondTrap Drag("D1");
		ClapTrap Clap1("C1");
		ClapTrap &Clap2 = Drag; //virtual fuc attack
		Clap1.attack("MET");
		Clap2.attack("MOT");
		Drag.attack("TOM");
		std::cout << "\n------------test1 done--------------\n\n";
	}
	{
		std::cout << "\n-----test2 for virtual Destructor------\n\n";
		ClapTrap *Clap = new DiamondTrap("HERO");
		Clap->attack("villain");
		delete Clap;
		std::cout << "\n------------test2 done--------------\n\n";
	}
	std::cout << "\n------main end------\n\n";
	return (0);
}

// int main()
// {
// 	DiamondTrap dia("HI");
// 	dia.attack("HAPPY");
// 	dia.beRepaired(100);
// 	dia.whoAmI();
// }
