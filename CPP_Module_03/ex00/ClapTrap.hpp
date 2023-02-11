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
		explicit ClapTrap(std::string);
		ClapTrap(const ClapTrap& obj);
		virtual ~ClapTrap();
		ClapTrap& operator=(const ClapTrap& obj);

		void takeDamage(unsigned int amount);
		void attack(const std::string& target);
		void beRepaired(unsigned int amount);

		std::string get_name() const;
		unsigned int get_attack_damage() const;
		bool use_energy_points();
};

#endif
