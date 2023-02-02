
# include <iostream>
# include <fstream>
# include <string>

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

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "agrument count error"<< std::endl;
		return (1);
	}
	else if (argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		std::cout << "null char is invalied" << std::endl;
		return (1);
	}
	std::string file_name,s1,s2;
	std::fstream fs;
	std::string line; //buff
	std::string ret; // ret_buff

	file_name = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	fs.open (argv[1], std::fstream::in);
	if (fs.fail())
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
			ret= ret + line;
		ret= ret + '\n';
		i++;
	}
	fs.close();
	file_name = file_name+".replace";

	/*for cpp99*/
	int len = file_name.size();
	char *c = new char[len + 1];
	std::copy(file_name.begin(), file_name.end(), c);
	c[len] = '\0';
	/*for cpp 99*/

	fs.open (c, std::fstream::out | std::fstream::trunc);
	if (fs.fail())
	{
		delete[] c;
		std::cout<< "cannot make file\n";
		return (1);
	}

	fs<<ret;
	fs.close();
	delete[] c;
}
