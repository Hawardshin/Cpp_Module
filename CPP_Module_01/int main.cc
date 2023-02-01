#include <iostream>

int main()
{
	std::string _name = "Bob";
	const std::string& name2 = "Bob";
	std::cout << _name<< name2<<"\n";
}
