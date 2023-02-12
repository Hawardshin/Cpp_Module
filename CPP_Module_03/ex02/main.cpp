# include "FragTrap.hpp"

// int main()
// {
// 	std::cout << "\n------main start------\n\n";
// 	{
// 		std::cout << "\n-----test1 for virtual fuction------\n\n";
// 		FragTrap Frag("S1");
// 		ClapTrap Clap1("C1");
// 		ClapTrap &Clap2 = Frag; //virtual fuc attack
// 		Clap1.attack("MET");
// 		Clap2.attack("MOT");
// 		Frag.attack("TOM");
// 		std::cout << "\n------------test1 done--------------\n\n";
// 	}
// 	{
// 		std::cout << "\n-----test2 for virtual Destructor------\n\n";
// 		ClapTrap *Clap = new FragTrap("HERO");
// 		Clap->attack("villain");
// 		delete Clap;
// 		std::cout << "\n------------test2 done--------------\n\n";
// 	}
// 	std::cout << "\n------main end------\n\n";
// 	return (0);
// }


int main()
{
	std::cout << "\n------main start------\n\n";
	FragTrap Frag("Frag");
	Frag.attack("TOM");
	Frag.takeDamage(5);
	Frag.beRepaired(5);
	Frag.highFivesGuys();
	std::cout << "\n------main end------\n\n";
	return (0);
}
