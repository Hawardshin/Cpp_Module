#pragma once

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
class Interns{
public:
    Interns();
    ~Interns();
    Form* makeForm(std::string form_name, std::string form_target);

private:
    Interns(const Interns& obj );
    Interns& operator=(const Interns& obj );

};
