#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money.You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
void	Harl::invaild_level(std::string level)
{
	std::cout << level <<" is invaild level\n you must input Vaild!!!!!!!!\n";
}

void	Harl::complain(std::string level)
{
	valid = true;
	void (Harl::*const	fp[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	const std::string	arr_level[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	switch (level[0])
	{
		case 'D' :	if (level == arr_level[0])
					{
						valid = 1;
						debug();
					}
					break;
		case 'I' :	if (level == arr_level[1])
					{
						valid = 1;
						info();
					}
					break;
		case 'W' :	if (level == arr_level[2])
					{
						valid = 1;
						warning();
					}
					break;
		case 'E' :	if (level == arr_level[3])
					{
						valid = 1;
						error();
					}
					break;
		default :	valid = 1;
					invaild_level(level);
	}
	if (valid != 0)
		invaild_level(level);

}
