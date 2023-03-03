#include "Bureaucrat.hpp"
#include "Form.hpp"

/* public */
Bureaucrat::Bureaucrat(const std::string& name, const int& grade) : name(name), grade(grade){
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

//It must attempt to execute the form.
//If it’s successful, print something like:
//<bureaucrat> executed <form>
void Bureaucrat:: executeForm(const Form& form){
  try {
    form.execute(*this);//in execute fuc check executable
    std::cout << "<bureaucrat> " << name << " executed <form> "<< form.getName() << "\n";
  }catch(std::exception& e){
    std::cout << "<bureaucrat> " << name << " connot executed <form> "<< form.getName() << "\n" << e.what() << "\n";
  }
}

void	Bureaucrat::signForm(Form& form_) {
	try{
    form_.beSigned(*this);
		std::cout << "<bureaucrat> "<< name<<" signed <form> " << form_.getName() <<"\n";
	} catch(std::exception& e)
	{
		std::cerr << "<bureaucrat> "<< name<<" couldn’t sign <form> " << form_.getName() <<\
		" because "<< e.what() <<"\n";
	}
}

//private
//which don't use default constructor
Bureaucrat::Bureaucrat(): name(""){}

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

std::ostream & operator<< (std::ostream &os, const Bureaucrat& obj){
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() <<"\n\n";
	return (os);
}

