
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>


class Zombie
{
	private :	std::string name;

	public :	Zombie(){};
				Zombie(std::string s){name= s;};
				void	announce(void);
				void	set_name(std::string);
				~Zombie(){std::cout << name << ": delete\n";};
};

Zombie*	newZombie(std::string s);
void randomChump(std::string name);

#endif
