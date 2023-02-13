#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap :  public virtual ClapTrap
{
public:
	FragTrap();
	explicit FragTrap(std::string);
	FragTrap(const FragTrap& obj );
	~FragTrap();//don't need virtual?
	FragTrap& operator=(const FragTrap& obj );

	void highFivesGuys(void);
	void attack(const std::string& target);
};

#endif
