#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {
  std::cout <<"[ScalarConverter Destructor called]\n" ;
}
//all type can convert to string
std::string ScalarConverter::my_dtos(const double& num_){
  std::ostringstream ss;
  ss << num_;
  std::cout << "param :"<< ss.str() << "\n";
  return ss.str();
}

bool  ScalarConverter::is_convertible(const char* param){
  double a = std::strtod(param,NULL); //is this right param NULL
  if (static_cast<std::string>(param) == ScalarConverter::my_dtos(a))
    return true;
  return false;
}

void  ScalarConverter::convert(const std::string& param){
 (void) param;
  // std::stringstream stream_data;
  // stream_data <<param;
  // // stream_data;
  // int a;
  // stream_data >> a ;
  // std::cout << a << "\n";
  // // static_cast<int> (stream_data) = m_int_;
}

//private
ScalarConverter::ScalarConverter() {
  std::cout <<"[ScalarConverter Default constructor called]\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) {
  static_cast<void> (obj);
  std::cout <<"[ScalarConverter Copy constructor called]\n";
}


ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj){
  std::cout <<"[ScalarConverter Copy assignment operator called]\n\n";
  static_cast<void> (obj);
  return (*this);
}
