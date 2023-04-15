
#include "Contact.hpp"

std::string&	Contact ::get_first_name(void){return(first_name);}
std::string&	Contact ::get_last_name(void){return(last_name);}
std::string&	Contact ::get_nickname(void){return(nickname);}
std::string&	Contact ::get_phone_number(void){return(phone_number);}
std::string&	Contact ::get_darkest_secret(void){return(darkest_secret);}

void	Contact ::set_first_name(std::string s){first_name=s;}
void	Contact ::set_last_name(std::string s){last_name=s;}
void	Contact ::set_nickname(std::string s){nickname=s;}
void	Contact ::set_phone_number(std::string s){phone_number=s;}
void	Contact ::set_darkest_secret(std::string s){darkest_secret=s;}

void	Contact ::show_all_info()
{
	std::cout<< "first name :"<<get_first_name() << "\n"
	<< "last name :" << get_last_name() << "\n"
	<< "nicname :"<< get_nickname() <<"\n"
	<<"phone number :"<<get_phone_number() << "\n"
	<<"darkest secret :"<< get_darkest_secret() << "\n";
}
