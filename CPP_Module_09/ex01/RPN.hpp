#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>
# include <algorithm>
# include <cctype>
# define ERROR_MSG "Error\n"
enum e_operator{
  IMPOSIBLE = -1,
  PLUS = 1,
  MINUS,
  DIV,
  MUL,
};

enum e_operator computable_operator(const char& c);
double calculate(const double& x,const double& y, const char &oper);
double my_pop(std::stack<double>& s);
#endif
