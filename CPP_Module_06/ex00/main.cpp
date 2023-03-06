#include "ScalarConverter.hpp"
int main(int argc,char **argv){
  if (argc != 2)
  {
    std::cout << "you must input one type\n";
    return (1);
  }
  ScalarConverter::convert(argv[1]);
}
