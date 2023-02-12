#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private :
		std::string name;

	public :
		DiamondTrap();
		explicit DiamondTrap(std::string);
		DiamondTrap &operator=(const DiamondTrap &obj);
		~DiamondTrap();

		void whoAmI();
		void attack(const std::string& target);

};


#endif
