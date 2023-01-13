// setw example
#include <iostream>// std::cout, std::endl
#include <iomanip>// std::setw
int main () {
	std::string input;
	std::cin >> input;
	if (input.size() <= 10)
	{
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout <<input;
	}
	else
	{
		for (int i=0;i < 9;i++) std::cout<< input[i];
		std::cout<< ".";
	}
	std::cout <<"|"<< std::endl;
	return 0;
}
