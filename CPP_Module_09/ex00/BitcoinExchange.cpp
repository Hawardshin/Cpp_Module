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
const char* BitcoinExchange::DATA_STARTLINE_ERROR = "Error: The DATA must start date | value\n";
const char* BitcoinExchange::BAD_INPUT_ERROR = "Error: bad input => ";
const char* BitcoinExchange::NOT_POSITIVE_ERROR = "Error: not a positive number.\n";
const char* BitcoinExchange::TOO_LARGENUM_ERROR = "Error: too large a number.\n";
const char* BitcoinExchange::DATE_TOO_EARLY = "Error: the date is too early so cannot calulate\n";
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) {csvData = obj.csvData;}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj){
	csvData = obj.csvData;
	return (*this);
}

void BitcoinExchange::initCsv(const int &argc) throw(std::invalid_argument&, std::runtime_error&){
  if (argc == 1)
    throw std::invalid_argument(OPEN_ERROR_MSG);
  if (argc != 2)
   throw std::invalid_argument (ARG_AMOUNT_ERROR_MSG);
  std::ifstream input_csv("data.csv");
  if (!input_csv.is_open())
    throw std::runtime_error("Error : there is no csv\n");
  try{
    parseCsv(input_csv);
  }
	catch(std::exception &e){
    std::cerr << e.what();
    input_csv.close();
    throw(std::invalid_argument(""));
  }
}

void	BitcoinExchange::coinToMoney(const char *argv_name) throw(std::invalid_argument&,std::runtime_error&){
  std::ifstream input_data(argv_name);
  if (!input_data.is_open())
    throw std::runtime_error(OPEN_ERROR_MSG);
  std::string Line;
  std::getline(input_data, Line);
  if (Line != "date | value"){
    input_data.close();
    throw std::invalid_argument(DATA_STARTLINE_ERROR);
  }
  while (std::getline(input_data, Line)){
    try{
      coinToMoneyOneLine(Line);
    }catch(std::exception& e){
      std::cerr << e.what();
    }
  }
}

void  BitcoinExchange::coinToMoneyOneLine(const std::string &line){
  size_t position = line.find('|');
  if (position == std::string::npos)
    throw(std::invalid_argument((std::string(BAD_INPUT_ERROR) + line + std::string("\n")).c_str()));
  std::string key = line.substr(0, position);
  IsDateVaild(key);
  double value = parseValue(line.substr(position+1));
  checkOverFlow(value);
  if (value > 1000)
    throw(std::invalid_argument(TOO_LARGENUM_ERROR));
  ExchangeMoney(key,value);
  //날짜가 DB에 있는 날보다 이른 경우 값을 구할 수 없음..!
  //해결법 : upperbound를 구하는데 그 값이 begin()값과 같으면 구할 수 없도록 한다.
}

void  BitcoinExchange::ExchangeMoney(const std::string &key, const double &value){
  std::map<std::string,double>::iterator it = csvData.upper_bound(key);
  if (it == csvData.begin())
    throw(std::invalid_argument(DATE_TOO_EARLY));
  it--;
  // std::ostringstream strs;
  // strs << (it->second * value);
  std::cout << key<<  " => " << value << " = " << it->second * value << "\n";
  // std::cout << key +std::string(" => ")+ strs.str() + std::string("\n");
}

void  BitcoinExchange::checkOverFlow(double d)throw(std::overflow_error&){
  int a = d;
  if (static_cast<double> (a) != std::floor(d))
    throw std::overflow_error(TOO_LARGENUM_ERROR);
}

//private
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
    //Q. is this ok? if end of line is seperator?
    //A. ok!!
		double value = parseValue(Line.substr(position+1));
		if (csvData.end() != csvData.find(key))
			throw(std::invalid_argument(DATE_OVERLAP_ERROR));
		csvData[key] = value;
  }
	input.close();
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

size_t BitcoinExchange::getSepPosition(const std::string &s,size_t &pos,size_t &befpos) throw (std::invalid_argument&){
	befpos = pos+1;
	size_t position = s.find('-',befpos);
	if (position == std::string::npos || position + 1 == s.length())
		throw(std::invalid_argument(DATE_INVALID_FORMAT));
	return (position);
}

int	BitcoinExchange::parseDate(const std::string &s) throw(std::invalid_argument&){
	int ret = 0;
	int len =0;
  // std::cout <<"PARSE::::" <<s << "\n";
	for (std::string::const_iterator it= s.begin(); it != s.end(); it++){
		if (*it < '0' || *it > '9')
    {
      if (len !=0 && *it == ' ' && it == s.end() - 1)//구분자 뒤에 ' '가 있는 경우는 예외로 처리한다.
        break;
			throw(std::invalid_argument(DATE_INVALID_FORMAT));
    }
		ret *= 10;
		ret += *it - '0';
		len++;
	}
	if (len == 0 || len > 4)
			throw(std::invalid_argument(DATE_INVALID_FORMAT));
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

double BitcoinExchange::parseValue(const std::string &s) throw(std::invalid_argument){
	double ret = std::atof(s.c_str());//공백만 있으면 0 공백이 있으면 밀고 시작.
  bool point =false;
  size_t sep_len = 0;
  while (s[sep_len] == ' '){
    sep_len++;
  }
  if (s[sep_len]== '\0')
    throw(std::invalid_argument(INVALID_DOUBLE_ERROR));
  for (size_t i = 0;  i+ sep_len < s.size();i++){
    if (!std::isdigit(s[i + sep_len])){
      if (i == 0 && s[i + sep_len] == '-')
        throw(std::invalid_argument(NOT_POSITIVE_ERROR));
      if (i == 0)
        throw(std::invalid_argument(INVALID_DOUBLE_ERROR));
      if (i != 0 && s[i + sep_len] == '.'&& !point)//.이면서 처음 나온경우
        point = true;
      else
        throw(std::invalid_argument(INVALID_DOUBLE_ERROR));
    }
  }
  try{
    checkOverFlow(ret);
  }
  catch(std::exception &e){
    throw(std::invalid_argument(""));
  }
	return (ret);
}
