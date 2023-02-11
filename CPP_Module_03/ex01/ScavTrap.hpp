#ifndef ScavTrap_HPP
# define ScavTrap_HPP
# include "Claptrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string);
	ScavTrap(const ScavTrap& obj );
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& obj );

	void guardGate();
	void attack(const std::string& target);
};

#endif
