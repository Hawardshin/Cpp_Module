#include "ScalarConverter.hpp"


ScalarConverter::~ScalarConverter() {
  std::cout <<"[ScalarConverter Destructor called]\n" ;
}
//char :
//int :
//float :
//double : when I start fuc use strtod(str); and check it is printable

//each of four thing
//first : detect the type of the literal passed as parameter,
//second : convert it from string to its actual type
//third : convert it explicitly to the three other data types.
//last : display four info
void  ScalarConverter::check_printable(t_printable &p, t_data &d,const std::string& literal){
  char *endptr_;
  p.double_flag = true;
  p.char_flag = true;
  p.int_flag = true;
  p.float_flag = true;
  d.double_data = std::strtod(literal.c_str(), &endptr_);
  if (strlen(endptr_) > 1 || (strlen(endptr_) == 1 && *endptr_ != 'f')) //check convertable
  {
    p.double_flag = false;
    if (literal.length() > 1)
      p.char_flag = false;
    p.int_flag = false;
    p.float_flag = false;
    return ;
  }
  d.int_data = static_cast<int>(d.double_data);
  d.char_data = static_cast<char>(d.double_data);
  d.float_data = static_cast<float>(d.double_data);
  if (static_cast<float>(d.double_data) == d.float_data)
  {
    if (d.double_data <= std::numeric_limits<float>::max() && d.double_data >= std::numeric_limits<float>::lowest())
      p.float_flag = true;
    else
      p.float_flag = false;
  }
  if (d.int_data != d.double_data)
    p.int_flag = false;
   if (d.char_data != d.double_data)
    p.char_flag = false;
}

void  ScalarConverter::print_data(t_printable &p, t_data &d){
  std::cout << "char: ";
  if (p.char_flag == false)
    std::cout << "impossible\n";
  else
  {
    if (static_cast<int> (d.char_data) > 31)
      std::cout << "\' "  << d.char_data << " \'"<< "\n";
    else
      std::cout << "Non displayable\n";
  }
  std::cout << "int: ";
  if (p.int_flag == false)
    std::cout << "impossible\n";
  else
    std::cout << d.int_data << "\n";
  std::cout << "float: ";
  if (p.float_flag == false)
    std::cout << "impossible\n";
  else
    std::cout << d.float_data << "\n";
  std::cout << "double: ";
  if (p.double_flag == false)
    std::cout << "impossible\n";
  else
    std::cout << d.double_data << "\n";
}

void  ScalarConverter::convert(const std::string& literal){
  t_printable print_flag;
  t_data      data;
  check_printable(print_flag, data, literal);
  print_data(print_flag,data);
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
