#include "Form.hpp"
// public
Form::Form(const std::string& name, const int& sign_grade,const int& exec_grade) : name(name), sign_grade(sign_grade),exec_grade(exec_grade),sign(false)
{
	check_except(*this);
	std::cout << "Bureaucrat Param constructor called\n";
	print_info();
}

//A boolean indicating whether it is signed (at construction, it’s not).
Form::Form(const Form& obj): name(obj.getName()), sign_grade(obj.getSignGrade()),exec_grade(obj.getExecGrade()),sign(false){
	check_except(obj);
	std::cout <<"Form Copy constructor called\n";
	print_info();
}

Form::~Form() {
	std::cout <<"Form Destructor called\n";
	print_info();
}

const std::string& Form::getName() const{ return (name); }

const int& Form::getSignGrade() const{ return (sign_grade); }

const int& Form::getExecGrade() const{ return (exec_grade); }

const bool& Form::getSign()const{return (sign);}

void Form:: check_except(const Form& obj) const{
	const int &sign_g = obj.getSignGrade();
	const int &exec_g = obj.getExecGrade();
	if (sign_g < 1  || exec_g < 1)
		throw GradeTooHighException();
	if (sign_g > 150 || exec_g > 150)
		throw GradeTooLowException();
}

void Form::print_info() const {
	std::cout << name << ", Form sign_grade " << sign_grade \
	<< ", exec_grade " << exec_grade << ", sign "<< std::boolalpha <<\
	sign << std::noboolalpha <<"\n\n";
}

void	Form::beSigned(const Bureaucrat& obj){
	if (obj.getGrade() <= sign_grade){
		sign = true;
	}
	else{
		throw GradeTooHighException();
	}
}

//private
//this default constructor will not use
Form::Form():name(""),sign_grade(1),exec_grade(1){}

Form& Form::operator=(const Form& obj){
	std::cout << "Form Copy assignment operator called\n";
	std::cout << "only sign change\n";
	sign = obj.sign;
	return (*this);
}

void Form:: check_exectutable(const Bureacrat& e){
  if (e.getGrade() <= exec_grade)

}

const char* Form::GradeTooHighException::what() const throw(){
	return ("Form Grade Too High\n");
}

const char* Form::GradeTooLowException::what() const throw(){
	return ("Form Grade Too Low\n");
}

std::ostream& operator<< (std::ostream &os, const Form& obj){
	os << obj.getName() << ", Form sign_grade " << obj.getSignGrade() \
	<< ", exec_grade " << obj.getExecGrade() << ", sign "<< std::boolalpha <<\
	obj.getSign() << std::noboolalpha <<"\n\n";
	return (os);
}
