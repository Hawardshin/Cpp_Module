
#include "main.hpp"

void PhoneBook::add_each_field(const std::string message, std:: string&field)
{
	std::cout << message;
	ft_cin(field);
	while (std::cin.eof() || check_printable(field))
	{
		print_not_valid();
		std ::cout << message;
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
	contact_array[idx] = contact;
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
	if (is_full ==false && idx == 0)
	{
		std::cout << "!!THERE IS ANY CONTACT IN PHONEBOOK!!\n";
		return ;
	}
	print_row_sep();
	std::cout << "|     index|"<< "first name|" << " last name|"<<"  nickname|\n";

	int	want_to_show(-1);
	do
	{
		std::cout<<"!!choose the right number want to see!!\n";
		fflush(stdin);
		std::cin.clear();
		clearerr(stdin);
		std::cin >> want_to_show;
		// std:: cout << want_to_show<<"\n";
	}
	while(std::cin.eof() || want_to_show < 1 || want_to_show > 8 || (!is_full && want_to_show > idx));
	contact_array[want_to_show - 1].show_all_info();
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
	std::cout << "         "<<i+1<<"|";
	print_in_rule(contact_array[i].get_first_name());
	print_in_rule(contact_array[i].get_last_name());
	print_in_rule(contact_array[i].get_nickname());
	std::cout <<std::endl;
}
