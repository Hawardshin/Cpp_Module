
#include <iostream>

int main()
{
	std::string s = "HI THIS IS BRAION";
	std::string *stringPTR = &s;
	std::string &stringREF = s;
	std::cout<<&s<<"\n"<< stringPTR << "\n" << &stringREF <<"\n";
	std::cout<<s<<"\n"<< *stringPTR << "\n" << stringREF <<"\n";
}
