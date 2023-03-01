#include "PresidentialPardonForm.hpp"

//public
PresidentialPardonForm::PresidentialPardonForm(const std::string& name) :Form(name, 25, 5) {
  std::cout <<"[PresidentialPardonForm parameter constructor called]\n" <<"You make " << name << "\n\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj):Form(obj.getName(), obj.getSignGrade(), obj.getExecGrade()){
  std::cout <<"[PresidentialPardonForm Copy constructor called]\n" <<"You make " << obj.name  << "\n\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout <<"[PresidentialPardonForm Destructor called]\n" <<"extinguish " << name  << "\n\n";
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const{
}

//private
PresidentialPardonForm::PresidentialPardonForm() :Form(){
  std::cout <<"[PresidentialPardonForm Default constructor called]\n" <<"You make " << name << "\n\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj){
  std::cout <<"[PresidentialPardonForm Copy assignment operator called]\n\n"
  name  = obj.name;
  return (*this);
}
