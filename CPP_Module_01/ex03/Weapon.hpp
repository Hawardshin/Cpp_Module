#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
	private : std::string type;

	public	:	Weapon(){type = "No weapon";}
				Weapon(std::string s) {type = s;}
				const std::string& getType();
				void	setType(std::string);
};

#endif
