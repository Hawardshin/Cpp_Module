#include "Harl.hpp"

int main()
{
	Harl h;
	int case_n(0);
	std::string	input;

	std::string complain_arr[4]  ={
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	std::cout << "CHOOSE THE COMPLAIN\n";
	for (int i(0);i<4;i++) std::cout <<i +1 << " : " <<  complain_arr[i] << "\n";
	std::cin >> input;
	for (; case_n < 4;case_n++){
		if (input == complain_arr[case_n])
			break;
	}
	switch (case_n)
	{
		case 0 :h.complain("DEBUG");

		case 1 : h.complain("INFO");

		case 2 : h.complain("WARNING");

		case 3 : h.complain("ERROR");
				break;
		default: h.complain("INVAILD");
				break;
	}
}
