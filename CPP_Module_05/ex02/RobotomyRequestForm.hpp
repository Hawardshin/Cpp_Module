#pragma once
#include "Form.hpp"
//RobotomyRequestForm: Required grades: sign 72, exec 45
//Makes some drilling noises.
//Then, informs that <target> has been robotomized successfully 50% of the time.
//Otherwise, informs that the robotomy failed.
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm:public Form {
private:
    RobotomyRequestForm();

public:
  explicit RobotomyRequestForm(const std::string & name);
  RobotomyRequestForm(const RobotomyRequestForm& obj );
  virtual ~RobotomyRequestForm();
  RobotomyRequestForm& operator=(const RobotomyRequestForm& obj );
  virtual void execute(const Bureaucrat& executor) const;
};
