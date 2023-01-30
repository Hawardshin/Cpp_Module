
#include "main.hpp"

void	replace_all(std::string &s, const std::string s1, const std::string s2)
{
	std::string head,tail;
	while (s.find(s1)!= std::string::npos)
	{
		int i = s.find(s1);
		s.erase(i, s1.size());
		s.insert(i,s2);
	}
}

int main()
{
	std::string file_name,s1,s2;
	std::fstream fs;
	std::string line;
	std::string ret;
	std::cout << "input file name and s1,s2\n";
	std::cin >> file_name >> s1>> s2;
	fs.open (file_name, std::fstream::in);
	if (fs.is_open() == false)
	{
		std::cout<< "cannot_open file\n";
		return (1);
	}
	int	i = 0;
	while(getline(fs, line)) {
		replace_all(line,s1,s2);
		if (i == 0)
			ret = line;
		else
			ret+=line;
		ret+='\n';
		i++;
	}
	fs.close();
	fs.open (file_name+".replace", std::fstream::out | std::fstream::trunc);
	fs<<ret;
}
