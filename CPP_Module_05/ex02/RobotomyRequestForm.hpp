#pragma once
//RobotomyRequestForm: Required grades: sign 72, exec 45
//Makes some drilling noises.
//Then, informs that <target> has been robotomized successfully 50% of the time.
//Otherwise, informs that the robotomy failed.
class RobotomyRequestForm
{
private:

public:
    RobotomyRequestForm();
    explicit RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& obj );
    ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& obj );
};
