#include "main.hpp"

//ADD, SEARCH EXIT.
static t_command	select_command()
{
	std::string input;
	std::cout<<"you can choose one ADD, SEARCH, EXIT\n";
	fflush(stdin);
	std::cin.clear();
	clearerr(stdin);
	std::cin >> input;
	if (input == "ADD")
		return (ADD);
	if (input == "SEARCH")
		return (SEARCH);
	if (input == "EXIT")
		return (EXIT);
	return (INVALID);
}

int main()
{
	PhoneBook phone_book;
	while (1)
	{
		switch(::select_command())
		{
			case ADD: 	phone_book.add_contact();
						break;
			case SEARCH: phone_book.search_contact();
						break;
			case EXIT:	return (0);
						break;
			default : ::print_not_valid();
		}
	}
	return (0);
}
