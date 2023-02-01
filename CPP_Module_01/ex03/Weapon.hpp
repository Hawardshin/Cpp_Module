#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
	private : std::string type;

	public	:	Weapon();
				Weapon(const std::string &);// 매개변수를 레퍼런스로 해도 되는걸까? 라는 걱정이 있었는데 된다고 판단.
				const std::string& getType(void);
				void	setType(const std::string);
};

#endif
