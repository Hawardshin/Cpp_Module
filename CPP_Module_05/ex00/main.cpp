#include "Bureaucrat.hpp"


int main()
{
	try
	{
		Bureaucrat A("Haward",1);
		std::cout << "Haward is ok\n";
		Bureaucrat B("Jack",15);
		std::cout << "Jack is ok\n";
		Bureaucrat C("Tom", 16);
		std::cout << "Tom is ok\n";
		Bureaucrat D("MIKE", -1);
		std::cout << "MIKE is ok\n";
	}
	catch(Bureaucrat:: GradeTooHighException &obj){
		std::cout << "Too High\n";
	}
	catch (Bureaucrat:: GradeTooLowException &obj){
		std::cout << "Too low\n";
	}
}
