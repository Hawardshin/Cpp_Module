#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "Claptrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	explicit FragTrap(std::string);
	FragTrap(const FragTrap& obj );
	~FragTrap();
	FragTrap& operator=(const FragTrap& obj );

	void highFivesGuys(void);
	void attack(const std::string& target);
};

#endif
