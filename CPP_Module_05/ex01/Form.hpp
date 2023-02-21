#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string name;
	bool sign;
	const int sign_grade;
	const int exec_grade;
	Form();

public:
	class GradeTooHighException {};
	class GradeTooLowException {};

	explicit Form(const std::string name,const int sign_grade,const int execgrade);
	Form(const Form& obj );
	~Form();
	Form& operator=(const Form& obj );
	std::string getName()const;
	bool getSign()const;
	int getSignGrade()const;
	int getExecGrade()const;

	void	check_except(int next_grade)const ;
	void	beSigned(Bureaucrat &obj);
	void	print_name_grade() const;
};

std::ostream & operator<<(std::ostream &os, const Form &obj);
