#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"
//B는 무장하지 않을 수 있다.
class HumanB{

private :	Weapon *weapon;
			std::string name;

public :	void	attack(void);
			HumanB(const std::string&);
			void	setWeapon(Weapon &weapon_);
};

#endif
