#include "RPN.hpp"

int


int main(int argc, char**argv){
  if (argc == 2)
  {
    std::stack<int> my_stack;
    std::string s(argv[1]);
    for (int i=0;i < s.size();i++){
      if (isDigit(s[i])){

      }
      else if (s[i]){

      }
      else {
        std::cout << ERROR_MSG;
        return (1);
      }
    }
  }
  else{
    std::cout << ERROR_MSG;
  }
  return (0);
}
