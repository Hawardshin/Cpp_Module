
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie
{
	private :	std::string _name;

	public :	Zombie(std::string);
				void	announce(void);
				void	set_name(std::string);
				~Zombie();
};

Zombie*	newZombie( std::string name );
void randomChump( std::string name );

#endif
