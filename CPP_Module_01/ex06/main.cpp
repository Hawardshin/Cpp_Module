#include "Harl.hpp"

int main(int argc, char **argv)
{
	std::string complain_arr[4]  ={
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	if (argc != 2) {
		std::cout << "CHOOSE THE COMPLAIN\n";
	for (int i(0);i<4;i++) std::cout <<" - " <<  complain_arr[i] << "\n";
		std::cout << "Arguments must be 2" << std::endl;
		return 1;
	}
	Harl h;
	int case_n(0);
	std::string	input(argv[1]);
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
