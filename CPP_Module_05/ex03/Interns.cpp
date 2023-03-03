#include "Interns.hpp"

//public
Interns::Interns() {
  std::cout <<"[Interns Default constructor called]\n\n";
}

Interns::~Interns() {
  std::cout <<"[Interns Destructor called]\n\n";
}

Form* Interns::makeForm(std::string form_name, std::string form_target){
  std::string Form_array[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
  int i;
  Form* form = NULL;
  for(i=0;i < 3;i++)
  {
    if (form_name == Form_array[i])
    {
      std::cout << "Intern creates <form>" << form_name << " ( " << form_target<<" ) "<< "\n\n";
      break;
    }
  }
  switch(i)
  {
    case 0 : form = new PresidentialPardonForm(form_target);
            break;
    case 1 :  form = new RobotomyRequestForm(form_target);
            break;
    case 2 : form = new ShrubberyCreationForm(form_target);
            break;
    default :  std::cout << "Intern can't creates <form>" << form_name << " ( " << form_target<<" ) "<< "\n\n";
  }
  return (form);
}

//private
Interns::Interns(const Interns &obj) {
  static_cast<void>(obj);
  std::cout <<"[Interns Copy constructor called]\n\n";
}

Interns& Interns::operator=(const Interns& obj){
  std::cout <<"[Interns Copy assignment operator called]\n\n";
  static_cast<void>(obj);
  return (*this);
}
