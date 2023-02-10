#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	private :
		std::string name;
		unsigned int Hit_points; //max is 10 min is 0
		unsigned int	Energy_points;////max is 10 min is 0
		int	Attack_damage;
	public :
		ClapTrap();
		ClapTrap(std::string);
		ClapTrap(const ClapTrap& obj);
		~ClapTrap();
		ClapTrap& operator=(const ClapTrap& obj);

		void takeDamage(unsigned int amount);
		void attack(const std::string& target);
		void beRepaired(unsigned int amount);

		std::string get_name();
		unsigned int get_attack_damage();
		bool use_energy_points();
};


#endif
