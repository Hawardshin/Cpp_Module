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

int main(int argc, char **argv){
  int st_size = -1;
  int i = 0;
  std::stack<double> my_stack;
  if (argc == 2){
    std::string s(argv[1]);
    st_size = s.size();
    for (i=0;i < st_size;i++){
      // std::cout << "ii: " << i << "\n";
      if (s[i]== ' ')
        continue ;
      if (std::isdigit(s[i]))
        my_stack.push(s[i] - '0');
      else if (computable_operator(s[i])){
        double y = my_pop(my_stack);
        double x = my_pop(my_stack);
        if (x == -1 || y == -1)
          break;
        my_stack.push(calculate(x,y,s[i]));
      }
      else
        break;
    }
  }
  if (i != st_size || my_stack.size() != 1)
    std::cout << ERROR_MSG;
  else
    std::cout <<my_pop(my_stack);
  return (0);
}
