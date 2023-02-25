#include "Bureaucrat.hpp"


int main()
{
	try
	{
		Bureaucrat A("Haward",1);
		std::cout << "Haward is ok\n\n";
		std::cout << A;
		Bureaucrat B("Jack",150);
		std::cout << "Jack is ok\n\n";
		Bureaucrat C("Tom", 151);
		std::cout << "Tom is ok\n\n";
	}
	catch(std::exception &e){
		std::cerr << e.what();
	}
	std::cout <<"\n--------------------1-----------------\n";
	try
	{
		Bureaucrat D("JJ",1);
		std::cout << "JJ is ok\n\n";
		Bureaucrat E("MIKE", -1);
		std::cout << "MIKE is ok\n\n";
	}
	catch(std::exception &e){
		std::cerr << e.what();
	}
	std::cout <<"\n--------------------2-----------------\n";
	try
	{
		Bureaucrat D("JJ",1);
		std::cout << "JJ is ok\n\n";
		D.decrement_grade();
		D.increment_grade();
		D.increment_grade();
	}
	catch(std::exception &e){
		std::cerr << e.what();
	}
	std::cout <<"\n---------------------3----------------\n";
	try
	{
		Bureaucrat D("JJ",149);
		std::cout << "JJ is ok\n\n";
		D.decrement_grade();
		D.decrement_grade();
	}
	catch(std::exception &e){
		std::cerr << e.what();
	}
	std::cout <<"\n---------------------4----------------\n";
}
