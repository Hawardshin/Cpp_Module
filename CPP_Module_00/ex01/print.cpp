
#include "main.hpp"

bool	check_printable(std ::string s){
	int	size(s.size());
	int	sp_cnt = 0;
	for (int i=0;i < size;i++){
		if (!(std:: isprint(s[i])))
			return (true);
		if (s[i] == ' ' || s[i] == '\n')
			sp_cnt++;
	}
	if (sp_cnt == size)
		return (true);
	return (false);
}

void	print_not_valid(void){
	std:: cout << "!!Please provide valid input!!\n";
}

void	print_in_rule(const std::string input)
{
	if (input.size() <= 10)
	{
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout <<input;
	}
	else
	{
		for (int i=0;i < 9;i++) std::cout<< input[i];
		std::cout<< ".";
	}
	std::cout <<"|";
}

void	print_row_sep(void){
	std::cout << "|----------|----------|----------|----------|\n";
}
