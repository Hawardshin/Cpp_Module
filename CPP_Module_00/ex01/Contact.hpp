#include <iostream>

class Contact
{
	private :	std ::string first_name;
				std ::string last_name;
				std ::string nickname;
				std ::string phone_number;
				std ::string darkest_secret;

	public :	void	add_contact(void);
				void	search_contact(void);
				void	print_contact(void);
				void	exit_contact(void);
};
