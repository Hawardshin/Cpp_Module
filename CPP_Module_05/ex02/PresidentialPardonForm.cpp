#include "PresidentialPardonForm.hpp"

//public
PresidentialPardonForm::PresidentialPardonForm(const std::string& name) :Form(name, 25, 5) {
  std::cout <<"[PresidentialPardonForm parameter constructor called]\n" <<"You make " << name << "\n\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj):Form(obj.getName(), obj.getSignGrade(), obj.getExecGrade()){
  std::cout <<"[PresidentialPardonForm Copy constructor called]\n" <<"You make " << obj.getName()  << "\n\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout <<"[PresidentialPardonForm Destructor called]\n" <<"extinguish " << getName() << "\n\n";
}

//this fuction throw exception so must wrapping
void PresidentialPardonForm::execute(const Bureaucrat& executor) const{
    check_exectutable(executor);
    std::cout <<"Informs that <target> "<< executor.getName() << " has been pardoned by Zaphod Beeblebrox.\n\n";
}

//private
PresidentialPardonForm::PresidentialPardonForm() :Form("", 25, 5){
  std::cout <<"[PresidentialPardonForm Default constructor called]\n";
}

//I am not use but other how to do it?
//how to change private base class member?
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj){
  // sign = obj.getSign();
  static_cast<void>(obj);
  std::cout <<"[PresidentialPardonForm Copy assignment operator called]\n\n";
  return (*this);
}
