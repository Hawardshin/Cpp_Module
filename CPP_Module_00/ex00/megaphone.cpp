
#include <iostream>

void	print_upper(std::string s)
{
	int size(s.size());
	for (int i=0;i <size;i++)
	{
		if ('a'<=s[i]&& s[i] <='z')
			std::cout <<(char)(s[i]^32);
		else
			std::cout << s[i];
	}
}

int main(int argc,char **argv)
{
	if (argc == 1)
		std ::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (int i=1;i < argc; i++)
		{
			print_upper((std::string)argv[i]);
		}
		std::cout<<std::endl;
	}
}
