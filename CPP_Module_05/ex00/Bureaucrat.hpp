#pragma once

#include <iostream>
#include <string>
#include <exception>
class Bureaucrat
{
public:
	Bureaucrat(const std::string&name,const int &grade_);
	Bureaucrat(const Bureaucrat& obj);
	~Bureaucrat();

	void 	check_except(int next_grade)const ;
	void	increment_grade();
	void	decrement_grade();
	const std::string &getName() const;
	const int 	&getGrade() const;
	void	print_name_grade() const;

private:
	const std::string name;
	Bureaucrat();
	int grade; // highest is 1 lowest is 150

	//because it has const member variable
	Bureaucrat& operator=(const Bureaucrat& obj );
	class GradeTooHighException: public std::exception{
		const char* what(void) const throw();
	};
	class GradeTooLowException: public std::exception{
		const char* what(void) const throw();
	};
};

std::ostream & operator<< (std::ostream &os, const Bureaucrat& obj);
