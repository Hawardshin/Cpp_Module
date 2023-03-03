#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
  try
  {
    Bureaucrat X("NO",190);
   }
  catch(std::exception &e)
  {
    e.what();
  }

  Bureaucrat A1("ADMIN", 1);
  Bureaucrat A2("BURE2",17);
  Bureaucrat A3("BURE3",75);
  std::cout << "---------------------------------1---------------------------\n\n";

  Form *F1 = new PresidentialPardonForm("PRESIDENT");
  Form *F2 = new RobotomyRequestForm("ROBOT");
  Form *F3 = new ShrubberyCreationForm("HOME");
  std::cout << "--------------------------------2----------------------------\n\n";
  std::cout << F1 << "\n" << F2 << "\n" << F3 << "\n";
  std::cout << *F1 << "\n" << *F2 << "\n" << *F3 << "\n";
  A1.executeForm(*F1);
  A1.executeForm(*F2);
  A1.executeForm(*F3);
  std::cout << "--------------------------------3----------------------------\n\n";
  A3.signForm(*F1);
  A3.signForm(*F2);
  A3.signForm(*F3);
  std::cout << "--------------------------------3.5----------------------------\n\n";
  A1.signForm(*F1);
  A1.signForm(*F2);
  A1.signForm(*F3);
  std::cout << "--------------------------------4----------------------------\n\n";
  A1.executeForm(*F1);
  A1.executeForm(*F2);
  A1.executeForm(*F3);
   std::cout << "--------------------------------5----------------------------\n\n";
  A3.executeForm(*F1);
  A3.executeForm(*F2);
  A3.executeForm(*F3);
  std::cout << "--------------------------------delete----------------------------\n\n";
  delete F1;
  delete F2;
  delete F3;
  // system("leaks Form");
  std::cout << "--------------------------------done----------------------------\n\n";
}
