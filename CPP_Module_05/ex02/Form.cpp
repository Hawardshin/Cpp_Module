#include "Form.hpp"

Form::Form() : name(""),sign(false), grade(0) {}

Form::Form(const std::string name, const int grade) : name(name),sign(false), grade(grade)
{
	check_except(grade);
	std::cout << "Bureaucrat Param constructor called\n";
	print_name_grade();
}

Form::Form(const Form &obj) :name(obj.name) ,grade(obj.getGrade()){ //is this right?
	std::cout <<"Form Copy constructor called\n";
	*this = obj;
	print_name_grade();
}

Form::~Form() {
	std::cout <<"Form Destructor called\n";
	print_name_grade();
}

Form& Form::operator=(const Form& obj){
	std::cout << "Form Copy assignment operator called\n";
	std::cout << "you can't change name so only grade change\n";
	*this = obj;//is this ok? Bureaucrat need check
	return (*this);
}
void Form:: check_except(int next_grade) const{
	if (next_grade > 150)
		throw GradeTooHighException();
	if (next_grade < 1)
		throw GradeTooLowException();
}

void	Form::beSigned(Bureaucrat &obj){
	if (obj.getGrade() <= grade)
	{
		std::cout << "bureaucrat’s grade is high enough\n" << \
		"so changes the form status to signed\n";
		sign = true;
	}
	else
		std::cout << "bureaucrat’s grade is not high enough\n";
	obj.print_name_grade();
}

std::string Form::getName() const{ return (name); }

int Form::getGrade() const{ return (grade); }

bool Form::getSign() const{ return (sign); }

void Form::print_name_grade() const {
	if (sign)
		std::cout << "Form is signed\n";
	else
		std::cout << "Form is unsigned\n";
	std::cout << name << ", Form grade " << grade <<"\n\n";
}

std::ostream & operator<< (std::ostream &os, const Form& obj){
	obj.print_name_grade();
	return (os);
}
