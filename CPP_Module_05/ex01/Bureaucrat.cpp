#include "Bureaucrat.hpp"
#include "Form.hpp"
Bureaucrat::Bureaucrat() { }

Bureaucrat::Bureaucrat(std::string name, int grade_) : name(name){
	check_except(grade_);
	grade = grade_;
	std::cout << "Bureaucrat Param constructor called\n";
	print_name_grade();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) {
	std::cout <<"Bureaucrat Copy constructor called\n";
	*this = obj;
	print_name_grade();
}

Bureaucrat::~Bureaucrat() {
	std::cout <<"Bureaucrat Destructor called\n";
	print_name_grade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj){
	std::cout << "Bureaucrat Copy assignment operator called\n";
	std::cout << "you can't change name so only grade change\n";
	grade = obj.grade;
	return (*this);
}

void Bureaucrat:: check_except(int next_grade) const{
	if (next_grade > 150)
		throw GradeTooHighException();
	if (next_grade < 1)
		throw GradeTooLowException();
}

void Bureaucrat::increment_grade(){
	check_except(grade -1);
	grade--;
	std::cout << "<increment_grade>\n";
	print_name_grade();
}

void Bureaucrat::decrement_grade(){
	check_except(grade + 1);
	grade++;
	std::cout << "<decrement_grade>\n";
	print_name_grade();
}

std::string Bureaucrat::getName() const{ return (name); }

int Bureaucrat::getGrade() const{ return (grade); }

void Bureaucrat::print_name_grade() const {
	std::cout << name << ", bureaucrat grade " << grade <<"\n\n";
}

void	Bureaucrat::signForm(Form &form_) const{//is this right prototype?
	if (form_.getSign())
		std::cout << "<bureaucrat> "<< name<<" signed <form> " << form_.getName() <<"\n";
	else
		std::cout << "<bureaucrat> "<< name<<" couldn’t sign <form> " << form_.getName() <<\
		"because "<< "grade is not enough\n";
}

std::ostream & operator<< (std::ostream &os, const Bureaucrat& obj){
	obj.print_name_grade();
	return (os);
}

