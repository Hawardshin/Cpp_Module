#include "RPN.hpp"

enum e_operator computable_operator(const char& c){
  if (c == '+')
    return (PLUS);
  if (c == '-')
    return (MINUS);
  if (c == '/')
    return(DIV);
  if (c == '*')
    return (MUL);
  return (IMPOSIBLE);
}

double calculate(const double& x,const double& y, const char &oper){
  switch(computable_operator(oper)){
    case PLUS : return(x + y);
    case MINUS : return (x - y);
    case DIV : return (x/y);
    case MUL : return (x*y);
    default : return (IMPOSIBLE);
  }
  return (IMPOSIBLE);
}

double my_pop(std::stack<double>& s){
  if (s.empty())
    return (-1);
  double n = s.top();
  s.pop();
  return (n);
}
