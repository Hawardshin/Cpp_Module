#include "Bureaucrat.hpp"

/* public */
Bureaucrat::Bureaucrat(const std::string&name, const int& grade) : name(name), grade(grade){
	check_except(grade);
	std::cout << "Bureaucrat Param constructor called\n";
	print_name_grade();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.getName()),grade(obj.getGrade()){
	std::cout <<"Bureaucrat Copy constructor called\n";
	check_except(grade);
	print_name_grade();
}

Bureaucrat::~Bureaucrat() {
	std::cout <<"Bureaucrat Destructor called\n";
	print_name_grade();
}

void Bureaucrat:: check_except(const int& next_grade) const{
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

const std::string& Bureaucrat::getName() const{ return (name); }

const int& Bureaucrat::getGrade() const{ return (grade); }

void Bureaucrat::print_name_grade() const {
	std::cout << name << ", bureaucrat grade " << grade <<"\n\n";
}

/* private */
Bureaucrat::Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj){
	std::cout << "Bureaucrat Copy assignment operator called\n";
	std::cout << "you can't change name so only grade change\n";
	grade = obj.grade;
	return (*this);
}

const char* Bureaucrat::GradeTooHighException:: what(void) const throw(){
	return ("Bureaucrat Grade Too High\n");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
  return ("Bureaucrat Grade Too Low\n");
}

// operator overoading
std::ostream & operator<< (std::ostream &os, const Bureaucrat& obj){
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() <<"\n\n";
	return (os);
}
