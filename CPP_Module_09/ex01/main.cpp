#include "RPN.hpp"



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
