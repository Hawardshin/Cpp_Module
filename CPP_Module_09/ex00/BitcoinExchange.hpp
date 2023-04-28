#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <sstream>
# include <iostream>
# include <algorithm>
# include <map>
# include <string>
# include <stdexcept>
# include <cstdlib>
# include <cmath>
class BitcoinExchange
{
public:
//이걸로 camel case하는 인간 없겠지?
  static const char* OPEN_ERROR_MSG;
  static const char* ARG_AMOUNT_ERROR_MSG;
  static const char* DATE_INVALID_FORMAT;
  static const char* INVALID_DOUBLE_ERROR;
  static const char* INVALID_LEAP_YEAR_ERROR;
  static const char* CSV_STARTLINE_ERROR;
  static const char* DATE_OVERLAP_ERROR;
  static const char* INVALID_DELIMITER;
  static const char* DATA_STARTLINE_ERROR;
  static const char* BAD_INPUT_ERROR;
  static const char* NOT_POSITIVE_ERROR;
  static const char* TOO_LARGENUM_ERROR;
  static const char* DATE_TOO_EARLY;
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& obj);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& obj );

	void initCsv(const int &argc) throw(std::invalid_argument&, std::runtime_error&);
	void	coinToMoney(const char *argv_name) throw(std::invalid_argument&,std::runtime_error&);
private:
	std::map<std::string, double> csvData;

  //parse csv
	void parseCsv(std::ifstream &input) throw(std::invalid_argument&);
	void IsDateVaild(const std::string &s) throw (std::invalid_argument&);
	size_t getSepPosition(const std::string &s,size_t &pos,size_t &befpos) throw (std::invalid_argument&);
	int	parseDate(const std::string &s) throw(std::invalid_argument&);
	void	checkLeapYear(int year, int month, int day) throw(std::invalid_argument&);
	double parseValue(const std::string &s) throw(std::invalid_argument);

//coin to money
  void  coinToMoneyOneLine(const std::string &line);
  void  checkOverFlow(double d) throw(std::overflow_error&);
  void  ExchangeMoney(const std::string &_key, const double &value);
};

#endif

