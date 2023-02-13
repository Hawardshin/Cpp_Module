#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap :  public virtual  ClapTrap
{
public:
	ScavTrap();
	explicit ScavTrap(std::string);
	ScavTrap(const ScavTrap& obj );
	~ScavTrap();//virtual?
	ScavTrap& operator=(const ScavTrap& obj );

	void guardGate();
	void attack(const std::string& target);
};

#endif
