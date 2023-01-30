#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"

//A는 항상 무장하지만
class HumanA{

private :	Weapon weapon;
			std::string name;

public :	void	attack(void);
			HumanA(const std::string&, const Weapon&);
};

#endif
