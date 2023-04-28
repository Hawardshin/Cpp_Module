#include "BitcoinExchange.hpp"
//public
const char* BitcoinExchange::OPEN_ERROR_MSG = "Error: could not open file.\n";
const char* BitcoinExchange::ARG_AMOUNT_ERROR_MSG = "Error: argument must be only one!!\n";
const char* BitcoinExchange::DATE_INVALID_FORMAT = "Error: Date format is not valid\n";
const char* BitcoinExchange::INVALID_DOUBLE_ERROR = "Error: Not double type\n";
const char* BitcoinExchange::INVALID_LEAP_YEAR_ERROR = "Error: wrong in leap years\n";
const char* BitcoinExchange::CSV_STARTLINE_ERROR = "Error: The csv must start date,exchange_rate\n";
const char* BitcoinExchange::DATE_OVERLAP_ERROR = "Error: The dates overlap!!\n";
const char* BitcoinExchange::INVALID_DELIMITER = "Error: Invalid delimiter!!\n";
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
    throw std::invalid_argument(OPEN_ERROR_MSG);
  if (argc != 2)
   throw std::invalid_argument (ARG_AMOUNT_ERROR_MSG);
  std::ifstream input_csv("data.csv");
  if (!input_csv.is_open())
    throw std::runtime_error("Error : there is no data\n");
	parseCsv(input_csv);
}



//private
int	BitcoinExchange::parseDate(const std::string &s) throw(std::invalid_argument&){
	int ret = 0;
	int len =0;
  // std::cout <<"PARSE::::" <<s << "\n";
	for (std::string::const_iterator it= s.begin(); it != s.end(); it++){
		if (*it < '0' || *it > '9')
			throw(std::invalid_argument(DATE_INVALID_FORMAT));
		ret *= 10;
		ret += *it - '0';
		len++;
	}
	if (len == 0 || len > 4)
			throw(std::invalid_argument(DATE_INVALID_FORMAT));
	return (ret);
}

double BitcoinExchange::parseDouble(const std::string &s) throw(std::invalid_argument){
	double ret = std::atof(s.c_str());
  bool point =false;
  for (size_t i = 0; i < s.size();i++){
    if (!std::isdigit(s[i])){
      if (i != 0 && s[i] == '.'&& !point)
        point = true;
      else
        throw(std::invalid_argument(INVALID_DOUBLE_ERROR));
    }
  }
	return (ret);
}

//400으로 나눠 떨어지면 윤년
//100으로 나눠 떨어지면 평년
//4로 나눠 떨어지면 윤년
//윤년은 29 평년은 28
void	BitcoinExchange::checkLeapYear(int year, int month, int day) throw(std::invalid_argument&){
	if (year < 1)
		throw(std::invalid_argument(INVALID_LEAP_YEAR_ERROR));
	if (month < 1 || month > 12)
		throw(std::invalid_argument(INVALID_LEAP_YEAR_ERROR));
	if (day < 1 || day > 31)
		throw(std::invalid_argument(INVALID_LEAP_YEAR_ERROR));
	if (day == 31 && ( month == 4 || month == 6 || month == 9 || month == 11))
		throw(std::invalid_argument(INVALID_LEAP_YEAR_ERROR));
	if (month == 2)
	{
		if (year %400 == 0)
		{
			if (day > 29)
				throw(std::invalid_argument(INVALID_LEAP_YEAR_ERROR));
		}
		else if (year % 100 == 0)
		{
			if (day > 28)
				throw(std::invalid_argument(INVALID_LEAP_YEAR_ERROR));
		}
		else if (year % 4 == 0){
			if (day > 29)
				throw(std::invalid_argument(INVALID_LEAP_YEAR_ERROR));
		}
		else if (day > 28)
				throw(std::invalid_argument(INVALID_LEAP_YEAR_ERROR));
	}
}

size_t BitcoinExchange::getSepPosition(const std::string &s,size_t &pos,size_t &befpos) throw (std::invalid_argument&){
	befpos = pos+1;
	size_t position = s.find('-',befpos);
	if (position == std::string::npos || position + 1 == s.length())
		throw(std::invalid_argument(DATE_INVALID_FORMAT));
	return (position);
}

void BitcoinExchange::IsDateVaild(const std::string &s) throw (std::invalid_argument&){
	//std::cout << "date" << s <<"\n";
	size_t befpos = 0,position = -1;
	position = getSepPosition(s,position,befpos);
	int year = parseDate(s.substr(befpos,position));
	//std::cout << "year" << year << "\n";
	position = getSepPosition(s,position,befpos);
	int month = parseDate(s.substr(befpos,position - befpos));
  //std::cout << "month" << month << "\n";
	int day = parseDate(s.substr(position + 1,s.length() - befpos));
	checkLeapYear(year, month, day);
}

void	BitcoinExchange::parseCsv(std::ifstream &input) throw(std::invalid_argument&){
  std::string Line;
  std::getline(input, Line);
  if (Line != "date,exchange_rate")
    throw(std::invalid_argument(CSV_STARTLINE_ERROR));
  while (std::getline(input, Line)){
		size_t position = Line.find(',');
		if (position == std::string::npos)
			throw(std::invalid_argument(INVALID_DELIMITER));
		std::string key = Line.substr(0, position);
		IsDateVaild(key);
		double value = parseDouble(Line.substr(position+1));
		if (csv_data.end() != csv_data.find(key))
			throw(std::invalid_argument(DATE_OVERLAP_ERROR));
		csv_data[key] = value;
  }
	input.close();
}


