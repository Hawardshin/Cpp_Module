
#include "Interns.hpp"
int main()
{
  Interns A;
  std::cout << "--------------------------------0000----------------------------\n\n";
  Form* F1 = A.makeForm("presidential pardon","First");
  Form* F2 = A.makeForm("robotomy request","Second");
  Form* F3 = A.makeForm("shrubbery creation", "HEE");
  Form* F4 = A.makeForm("NOIN","HOO");
  std::cout << "--------------------------------111111----------------------------\n\n";
  static_cast<void>(F4);
  delete F1;
  delete F2;
  delete F3;
  // system("leaks Form");
  std::cout << "--------------------------------done----------------------------\n\n";

}
