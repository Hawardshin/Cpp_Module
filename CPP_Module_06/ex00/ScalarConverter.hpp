#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
typedef struct s_printable{
    bool  double_flag;
    bool  char_flag;
    bool  int_flag;
    bool  float_flag;
  }t_printable;
typedef struct s_data{
  int int_data;
  char char_data;
  float float_data;
  double double_data;
}t_data;

//it's static class I will not make instance
class ScalarConverter
{
public:
  static void convert(const std::string& param);
  ~ScalarConverter();

private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter& obj );
  ScalarConverter& operator=(const ScalarConverter& obj );

  static void check_printable(t_printable &p, t_data &d,const std::string& literal);
  static void print_data(t_printable &p, t_data &d);
};
