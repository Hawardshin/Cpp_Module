#include "BitcoinExchange.hpp"
//public
BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) {
	csv_data = obj.csv_data;
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj){
	csv_data = obj.csv_data;
	return (*this);
}

void BitcoinExchange::initCsv(const int &argc) throw(std::invalid_argument&, std::runtime_error&){
  if (argc == 1)
    throw std::invalid_argument( "Error: could not open file.\n");
  if (argc != 2)
   throw std::invalid_argument ("Error: argument must be only one!!\n");
  std::ifstream input_csv("data.csv");
  if (!input_csv.is_open())
    throw std::runtime_error("Error : there is no data\n");
	parseCsv(input_csv);
}
//private
int	BitcoinExchange::parseInt(const std::string &s) throw(std::invalid_argument&){
	int ret = 0;
	int len =0;
	std::cout <<"PARSE::::" <<s << "\n";
	for (std::string::const_iterator it= s.begin(); it != s.end(); it++){
		if (*it < '0' || *it > '9')
			throw(std::invalid_argument("Error : Date Not Number\n"));
		ret *= 10;
		ret += *it - '0';
		len++;
	}
	if (len == 0 || len > 4)
			throw(std::invalid_argument("Error: Date num is not valid\n"));
	return (ret);
}

//이거 살짝 애매해 double이 이렇게 검사가 가능한지..?
double BitcoinExchange::parseDouble(const std::string &s) throw(std::invalid_argument){
	double ret = std::atof(s.c_str());
	std::stringstream ss;
	ss << ret;
	if (ss.str() != s)
		throw(std::invalid_argument("Error: The value is in an incorrect format\nNot double type\n"));
	return (ret);
}

//400으로 나눠 떨어지면 윤년
//100으로 나눠 떨어지면 평년
//4로 나눠 떨어지면 윤년
//윤년은 29 평년은 28
void	BitcoinExchange::checkLeapYear(int year, int month, int day) throw(std::invalid_argument&){
	if (year < 1)
		throw(std::invalid_argument("Error: The Date is in an incorrect format\nYear!!!\n"));
	if (month < 1 || month > 12)
		throw(std::invalid_argument("Error: The Date is in an incorrect format\nMonth!!!\n"));
	if (day < 1 || day > 31)
		throw(std::invalid_argument("Error: The Date is in an incorrect format\nday!!!\n"));
	if (day == 31 && ( month == 4 || month == 6 || month == 9 || month == 11))
		throw(std::invalid_argument("Error: The Date is in an incorrect format\nday!!!\n"));
	if (month == 2)
	{
		if (year %400 == 0)
		{
			if (day > 29)
				throw(std::invalid_argument("Error: The Date is in an incorrect format\nLeapYear day!!!\n"));
		}
		else if (year % 100 == 0)
		{
			if (day > 28)
				throw(std::invalid_argument("Error: The Date is in an incorrect format\nLeapYear day!!!\n"));
		}
		else if (year % 4 == 0){
			if (day > 29)
				throw(std::invalid_argument("Error: The Date is in an incorrect format\nLeapYear day!!!\n"));
		}
		else if (day > 28)
				throw(std::invalid_argument("Error: The Date is in an incorrect format\nLeapYear day!!!\n"));
	}
}

size_t BitcoinExchange::getSepPosition(const std::string &s,size_t &pos,size_t &befpos) throw (std::invalid_argument&){
	befpos = pos+1;
	std::cout << "befos" << befpos << "\n";
	size_t position = s.find('-',befpos);
	std::cout << "pos" << position << "\n";
	if (position == std::string::npos || position + 1 == s.length())
		throw(std::invalid_argument("Error: The csv is in an incorrect format\nDate format!\n"));
	return (position);
}

void BitcoinExchange::IsDateVaild(const std::string &s) throw (std::invalid_argument&){
	std::cout << "date" << s <<"\n";
	size_t befpos = 0,position = -1;
	position = getSepPosition(s,position,befpos);
	int year = parseInt(s.substr(befpos,position));
	std::cout << "year" << year << "\n";
	position = getSepPosition(s,position,befpos);
	int month = parseInt(s.substr(befpos+1,position));
		std::cout << "month" << month << "\n";
	position = getSepPosition(s,position,befpos);
	int day = parseInt(s.substr(befpos+1, position));
	checkLeapYear(year, month, day);
}

void	BitcoinExchange::parseCsv(std::ifstream &input) throw(std::invalid_argument&){
  std::string Line;
  std::getline(input, Line);
  if (Line != "date,exchange_rate")
    throw(std::invalid_argument("Error: The csv is in an incorrect format\nMust csv start date,exchange_rate\n"));
  while (std::getline(input, Line)){
		size_t position = Line.find(',');
		if (position == std::string::npos)
			throw(std::invalid_argument("Error: The csv is in an incorrect format\nMust csv seperate by ,\n"));
		std::string key = Line.substr(0, position);
		IsDateVaild(key);
		double value = parseDouble(Line.substr(position+1));
		if (csv_data.end() != csv_data.find(key))
			throw(std::invalid_argument("Error: The csv is in an incorrect format\nMust csv only one date\n"));
		csv_data[key] = value;
  }
	input.close();
}


