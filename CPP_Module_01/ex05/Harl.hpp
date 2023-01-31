#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
	private :	bool	valid;
				void	debug( void );
				void	info( void );
				void	warning( void );
				void	error( void );
				void	invaild_level(std::string level);

	public :	void complain(std::string level);
}



#endif
