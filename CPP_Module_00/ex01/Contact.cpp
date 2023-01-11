
#include "Contact.hpp"
//
//
bool	check_printable(std ::string s)
{
	int	size(s.size());
	for (int i=0;s[i] < size;i++)
	{
		if (!(std:: isprint(s[i])))
			return (1);
	}
	return (0);
}
void	print_non_printable(void)
{
	std:: cout << "your input contain nonprintable ascii\n"
				<< "you must input printable ascii\n";
}
void	Contact ::add_contact(void)
{
	std ::cout << "please input first name\n";
	std ::cin >> first_name;
	while (check_printable(first_name))
	{
		print_non_printable();
		std ::cout << "please input first name\n";
		std ::cin >> first_name;
	}
	std ::cout << first_name;
	std ::cout << "please input last name\n";
	std ::cin >> first_name;
	while (last_name != ""){
		std ::cout << "please input last name\n";
		std ::cin >> first_name;
	}

	std ::cout << "please input nickname\n";
	while (!(std ::cin >> nickname)){
		std ::cout << "please input nickname\n";
	}

	std ::cout << "please input phone number\n";
	while (!(std ::cin >> phone_number)){
		std ::cout << "please input phone number\n";
	}

	std ::cout << "please input darkest secret\n";
	while (!(std ::cin >> darkest_secret)){
		std ::cout << "please input darkest secret\n";
	}
}

void	Contact ::search_contact(void)
{

}

void	Contact ::print_contact(void)
{

}

void	Contact ::exit_contact(void)
{

}
