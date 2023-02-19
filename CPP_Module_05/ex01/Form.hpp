#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string name;
	bool sign;
	const int grade;
	Form();
public:
	class GradeTooHighException {};
	class GradeTooLowException {};
	Form(const Form& obj );
	~Form();
	Form& operator=(const Form& obj );
	const std::string getName()const;
	bool getSign()const;
	const int getGrade() const;
	void	beSigned(Bureaucrat &obj);
};

std::ostream & operator<<(std::ostream &os, const Form &obj){

}
