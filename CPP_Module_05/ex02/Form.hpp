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

	explicit Form(const std::string name,const int grade);
	Form(const Form& obj );
	virtual ~Form();
	Form& operator=(const Form& obj );
	std::string getName()const;//is this right infront of getter const type?
	bool getSign()const;
	virtual int getGrade() const = 0; // is this ok? virtaul to this fuction?

	void	check_except(int next_grade)const ;
	void	beSigned(Bureaucrat& obj);
	void	print_name_grade() const;
};

std::ostream & operator<<(std::ostream &os, const Form& obj);
