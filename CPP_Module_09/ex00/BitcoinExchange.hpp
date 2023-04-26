#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <sstream>
# include <iostream>
# include <algorithm>
# include <map>
# include <string>
# include <stdexcept>
#include <cstdlib>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& obj);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& obj );
	void initCsv(const int &argc) throw(std::invalid_argument&, std::runtime_error&);

private:
	std::map<std::string, double> csv_data;
	size_t getSepPosition(const std::string &s,size_t &pos,size_t &befpos) throw (std::invalid_argument&);
	int	parseInt(const std::string &s) throw(std::invalid_argument&);
	double parseDouble(const std::string &s) throw(std::invalid_argument);
	void IsDateVaild(const std::string &s) throw (std::invalid_argument&);
	void	checkLeapYear(int year, int month, int day) throw(std::invalid_argument&);
	void parseCsv(std::ifstream &input) throw(std::invalid_argument&);
};
#endif
