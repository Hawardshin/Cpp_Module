
#include "main.hpp"

void PhoneBook::add_each_field(const std::string message, std:: string&field)
{
	std::cout << message;
	ft_cin(field);
	while (std::cin.eof() || check_printable(field))
	{
		print_not_valid();
		std ::cout << "please input first name\n";
		ft_cin(field);
	}
}

void	PhoneBook::add_contact(void)
{
	Contact	contact;

	add_each_field("please input first name\n",contact.get_first_name());
	add_each_field("please input last name\n",contact.get_last_name());
	add_each_field("please input nickname\n",contact.get_nickname());
	add_each_field("please input phone number\n",contact.get_phone_number());
	add_each_field("please input darkest secret\n",contact.get_darkest_secret());
	num_array[idx] = contact;
	idx++;
	if (idx == 8)
	{
		is_full = true;
		idx = 0;
	}
}

//index, first name, last name and nickname.
void	PhoneBook ::search_contact(void)
{
	print_row_sep();
	std::cout << "|     index|"<< "first name|" << " last name|"<<"  nickname|\n";
	print_row_sep();
	int size= idx;
	if (is_full== true)
		size=8;
	for (int i=0;i < size;i++)
	{
		if (idx -size + i < 0)
		{
			print_each_col(idx -size + i + 8);
		}
		else
			print_each_col(idx -size + i);
	}
}

void	PhoneBook ::ft_cin(std::string &s)
{
	fflush(stdin);
	std::cin.clear();
	clearerr(stdin);
	getline(std::cin,s);
}

void	PhoneBook ::print_each_col(int i)
{
	std::cout << "|";
	std::cout << "        "<<i<<".|";
	print_in_rule(num_array[i].get_first_name());
	print_in_rule(num_array[i].get_last_name());
	print_in_rule(num_array[i].get_nickname());
	std::cout <<std::endl;
}
