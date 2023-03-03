
#include "Interns.hpp"
int main()
{
  Form* F1 = makeForm("presidential pardon",First);
  Form* F2 = makeForm("robotomy request",Second);
  Form* F3 = makeForm("shrubbery creation", );
  Form* F4 = makeForm("NOIN");
  delete F1;
  delete F2;
  delete F3;
  system("leaks Form");
  std::cout << "--------------------------------done----------------------------\n\n";

}
