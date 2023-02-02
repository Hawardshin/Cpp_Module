#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"
//B는 무장하지 않을 수 있다.
class HumanB{

private :	std::string name;
			Weapon *weapon;


public :	HumanB(const std::string&);
			void	attack(void);
			void	setWeapon(Weapon &weapon_);
};

#endif
