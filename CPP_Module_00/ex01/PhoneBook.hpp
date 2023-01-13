#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"

typedef enum e_command
{
	ADD,
	SEARCH,
	EXIT,
	INVALID
}t_command;

class PhoneBook
{
	private :	int idx;
				bool is_full;
				Contact contact_array[8];

	public :	void	print_each_col(int );
				void	add_each_field(const std::string, std::string&);
				void	add_contact(void);
				void	ft_cin(std::string&);
				void	search_contact(void);
};

#endif
