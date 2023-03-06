#pragma once
#include <string>
#include <iostream>
#include <sstream>
//origin string is compare by after convert string
//is this ok nan and inf go to strtod fuc what is return?
//can i check this input to use isnan or isinf? test go
//char :
//int :
//float :
//double : when I start fuc use strtod(str); and check it is printable
//strtod() var to back string use ostringstream if it is diff fail first

//it is static class so I will init origin string in convert fuc

class ScalarConverter
{
public:
  static std::string my_dtos(const double& num_);
  static bool  is_convertible(const char* param);
  static void convert(const std::string& param);
  ~ScalarConverter();

private:
  static std::string s_origin_str_;
  ScalarConverter();
  ScalarConverter(const ScalarConverter& obj );
  ScalarConverter& operator=(const ScalarConverter& obj );

};
