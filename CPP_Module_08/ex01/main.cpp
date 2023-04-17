#include "Span.hpp"

int main()
{
  Span sp = Span(6);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  std::cout << "\n---------------------1-------------------\n";
  try{
    //one thing and longestSpan
     Span a(10);
    a.addNumber(5);
    a.longestSpan();
    std::cout << "good\n";
  }
  catch(std::exception &e){
     std::cout <<  e.what() << "\n";
  }
  std::cout << "\n---------------------2-------------------\n";
  try{
    Span n_sp(sp);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  catch(std::exception &e){
     std::cout <<  e.what() << "\n";
  }
  std::cout << "\n---------------------3-------------------\n";
  try{
    //span max size
    Span two(2);
    two.addNumber(1);
    std::cout << "push 1\n";
    two.addNumber(2);
    std::cout << "push 2\n";
    two.addNumber(3);
    std::cout << "push 3\n";
  }
  catch(std::exception &e){
     std::cout <<  e.what() << "\n";
  }
  std::cout << "\n---------------------4-------------------\n";
  try{
    //max size num limit
    Span two(2);
    two.addNumber(std::numeric_limits<int>::max());
    std::cout << "push 1\n";
    two.addNumber(std::numeric_limits<int>::min());
    std::cout << "push 2\n";
    std::cout << two.shortestSpan() << std::endl;
    std::cout << two.longestSpan() << std::endl;
    std::cout << std::numeric_limits<unsigned int>::max() << "\n";
  }
  catch(std::exception &e){
     std::cout <<  e.what() << "\n";
  }
  std::cout << "\n---------------------5-------------------\n";
  try { // copy operator test
    Span n_sp(5);
    n_sp = sp;
    std::cout << n_sp.shortestSpan() << std::endl;
    std::cout << n_sp.longestSpan() << std::endl;
  }
   catch(std::exception &e){
     std::cout <<  e.what() << "\n";
  }
  std::cout << "\n---------------------6-------------------\n";
  try {
    Span rand_(10000);
    rand_.initNumberRange(10000);
    std::cout << rand_.shortestSpan() << std::endl;
    std::cout << rand_.longestSpan() << std::endl;
  }
   catch(std::exception &e){
     std::cout <<  e.what() << "\n";
  }
  std::cout << "\n---------------------end-------------------\n";
  // system("leaks ex01");
  return 0;
}
