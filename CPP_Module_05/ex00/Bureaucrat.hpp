#pragma once

#include <iostream>
#include <string>
#include <exception>
class Bureaucrat
{
private:
	const std::string name;
	int grade; // highest is 1 lowest is 150

	class GradeTooHighException: public std::exception{
		const char* what(void) const throw();
	};
	class GradeTooLowException: public std::exception{
		const char* what(void) const throw();
	};

	//because it has const member variable
	Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& obj );
	Bureaucrat(const Bureaucrat& obj);

public:
	Bureaucrat(const std::string&name,const int &grade_);
	~Bureaucrat();

	void 	check_except(int next_grade)const ;
	void	increment_grade();
	void	decrement_grade();
	const std::string &getName() const;
	const int 	&getGrade() const;
	void	print_name_grade() const;
};

std::ostream & operator<< (std::ostream &os, const Bureaucrat& obj);
