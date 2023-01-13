#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
class Contact
{
	private :	std ::string first_name;
				std ::string last_name;
				std ::string nickname;
				std ::string phone_number;
				std ::string darkest_secret;

	public :	std::string&	get_first_name(void);
				std::string&	get_last_name(void);
				std::string&	get_nickname(void);
				std::string&	get_phone_number(void);
				std::string&	get_darkest_secret(void);
				void			set_first_name(std::string s);
				void			set_last_name(std::string s);
				void			set_nickname(std::string s);
				void			set_phone_number(std::string s);
				void			set_darkest_secret(std::string s);
				void			show_all_info();

};



#endif
