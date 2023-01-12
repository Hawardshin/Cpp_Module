
#include "main.hpp"

bool	check_printable(std ::string s){
	int	size(s.size());
	for (int i=0;i < size;i++){
		if (!(std:: isprint(s[i])))
			return (true);
	}
	return (false);
}

void	print_not_valid(void){
	std:: cout << "!!Please provide valid input!!\n";
}

void	print_in_rule(const std::string s)
{
	int size(s.size());
	if (size<9)
	{
		for (int i=0;i < 9-size;i++) std::cout<<" ";
		std::cout << s;
	}
	else
		for (int i=0;i < 9;i++) std::cout<<s[i];
	std::cout << ".|";
}

void	print_row_sep(void){
	std::cout << "|----------|----------|----------|----------|\n";
}
