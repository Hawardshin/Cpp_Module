#ifndef ScavTrap_HPP
# define ScavTrap_HPP
# include "Claptrap.hpp"

class ScavTrap : public ClapTrap
{
private:

public:
	ScavTrap();
	ScavTrap(const ScavTrap& obj );
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& obj );
};

#endif
