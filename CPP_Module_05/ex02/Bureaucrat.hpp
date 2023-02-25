#pragma once

#include <iostream>
#include <string>
class Form;

class Bureaucrat
{
private:
	const std::string name;
	int grade; // 1~150
	//highest is 1 lowest is 150
	Bureaucrat();

public:
	class GradeTooHighException{};
	class GradeTooLowException{};
	explicit Bureaucrat(std::string name,int grade_);
	Bureaucrat(const Bureaucrat& obj );
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& obj );

	void		check_except(int next_grade)const ;
	void		increment_grade();
	void		decrement_grade();
	std::string	getName() const;
	int 		getGrade() const;
	void		print_name_grade() const;
	void		signForm(Form& form_) const;//
};

std::ostream & operator<< (std::ostream &os, const Bureaucrat& obj);
