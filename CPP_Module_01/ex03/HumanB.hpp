#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB{

private :	Weapon weapon;
			std::string name;

public :	void	attack(void);
			HumanB(std::string s){name = s;}
			void	setWeapon(Weapon &we){ weapon = we;}
};

#endif
