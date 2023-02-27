#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
public:
	Form(const std::string& name,const int& sign_grade,const int& execgrade);
	Form(const Form& obj);
	~Form();

	const std::string& getName()const;
	const int& getSignGrade()const;
	const int& getExecGrade()const;
	const bool& getSign()const;
	void	beSigned(const Bureaucrat& obj);


private:
	Form();
	const std::string name;
	const int sign_grade;
	const int exec_grade;
	bool sign;

	Form& operator=(const Form& obj );
	void	print_info() const;
	void	check_except(const Form& obj) const;
	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw() ;
	};
	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw() ;
	};
};

std::ostream & operator<<(std::ostream &os, const Form& obj);
