#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form A("Haward",1);
		std::cout << "Haward is ok\n\n";
		Form B("Jack",150);
		std::cout << "Jack is ok\n\n";
		Form C("Tom", 151);
		std::cout << "Tom is ok\n\n";
	}
	catch(Form:: GradeTooHighException &obj){
		std::cout << "!!!!!!!Too High\n\n";
	}
	catch (Form:: GradeTooLowException &obj){
		std::cout << "!!!!!!!Too low\n\n";
	}
	try
	{
		Form D("JJ",1);
		std::cout << "!!!!!!!JJ is ok\n\n";
		Form E("MIKE", 0);
		std::cout << "!!!!!!!MIKE is ok\n\n";
	}
	catch(Form:: GradeTooHighException &obj){
		std::cout << "!!!!!!!Too High\n";
	}
	catch (Form:: GradeTooLowException &obj){
		std::cout << "!!!!!!!Too low\n";
	}
	try
	{
		Bureaucrat D("Dong",1);
		std::cout << "D is ok\n\n";
		Form X("XX",1);
		Bureaucrat Y("YY",2);
		X.beSigned(Y);
		Y.signForm(X);
		X.beSigned(D);
		Y.signForm(X);
	}
	catch(Form:: GradeTooHighException &obj){
		std::cout << "Form!!!!!!!Too High\n";
	}
	catch (Form:: GradeTooLowException &obj){
		std::cout << "Form!!!!!!!Too low\n";
	}
	catch(Bureaucrat:: GradeTooHighException &obj){
		std::cout << "Bureaucrat!!!!!!!Too High\n\n";
	}
	catch (Bureaucrat:: GradeTooLowException &obj){
		std::cout << "Bureaucrat!!!!!!!Too low\n\n";
	}
}
