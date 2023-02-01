#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]\n"<<
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
	<<"I really do!\n\n";
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]\n"<<
	"I cannot believe adding extra bacon costs more money.\n"
	<<"You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n\n";
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]\n"<<
	"I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n"
	<<"I've been coming for years whereas you started working here since last month.\n\n";
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]\n"<<
	"This is unacceptable! I want to speak to the manager now.\n\n";
}
void	Harl::invaild_level(void)
{
	std::cout <<"[ Probably complaining about insignificant problems ]\n";
}

void	Harl::complain(std::string level)
{
	void (Harl::*const	fp[5])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
		&Harl::invaild_level,
	};
	const std::string	arr_level[5] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
		"INVAILD"
	};
	for (int i=0;i < 5;i++){
		if(level == arr_level[i])
			(this->*fp[i])();
	}
}
