#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	explicit ScavTrap(std::string);
	ScavTrap(const ScavTrap& obj );
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& obj );

	void guardGate();
	void attack(const std::string& target);
};

#endif
