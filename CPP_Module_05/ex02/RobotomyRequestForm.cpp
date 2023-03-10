//Copyright (c) 2023 Hawardshin(joushin)
#include "RobotomyRequestForm.hpp"

//public
RobotomyRequestForm::RobotomyRequestForm(const std::string& name) :Form(name, 72, 45) {
  std::cout <<"[RobotomyRequestForm parameter constructor called]\n" <<"You make " << name << "\n\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj):Form(obj.getName(), obj.getSignGrade(), obj.getExecGrade()){
  std::cout <<"[RobotomyRequestForm Copy constructor called]\n" <<"You make " << obj.getName()  << "\n\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout <<"[RobotomyRequestForm Destructor called]\n" <<"extinguish " << getName() << "\n\n";
}

//Makes some drilling noises.
//Then, informs that <target> has been robotomized successfully 50% of the time.
void RobotomyRequestForm::execute(const Bureaucrat& executor) const{
  check_exectutable(executor);
  std::cout << "zzzzzzz\n";
  srand((unsigned int)time(NULL));//for seed change by time
  if (std::rand() % 2 == 0){
    std::cout << "<target> " << executor.getName()<<" has been robotomized successfully\n\n";
  } else{
      std::cout << "<target> " << executor.getName()<<" has been robotomized failly\n\n";
  }
}

//private
RobotomyRequestForm::RobotomyRequestForm() :Form("", 72, 45){
  std::cout <<"[RobotomyRequestForm Default constructor called]\n";
}

//I am not use it
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj){
  static_cast<void>(obj);
  std::cout <<"[RobotomyRequestForm Copy assignment operator called]\n\n";
  return (*this);
}
