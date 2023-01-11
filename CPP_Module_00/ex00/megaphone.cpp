
#include <iostream>

int main(int argc,char **argv)
{
	if (argc == 1)
		std ::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else if (argc == 2 && (std ::string)argv[1] == "shhhhh... I think the students are asleep...")
		std ::cout << "SHHHHH... I THINK THE STUDENTS ARE ASLEEP...\n";
	else if (argc == 4 && (std ::string)argv[1] == "Damnit"  && (std ::string)argv[2] == " ! " && (std ::string)argv[3] == "Sorry students, I thought this thing was off.")
		std ::cout << "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.\n";
}
