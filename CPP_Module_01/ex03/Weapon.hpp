#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
	private : std::string type;

	public	:	Weapon(std::string );
				const std::string& getType(void);
				void	setType(const std::string);
};

#endif
