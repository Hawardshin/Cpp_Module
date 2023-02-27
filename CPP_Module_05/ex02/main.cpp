#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form A("Haward",1,10);
		std::cout << "Haward is ok\n\n";
		Form B("Jack",150,1);
		std::cout << "Jack is ok\n\n";
    std::cout << B;
    Bureaucrat X("X-man",2);
    X.signForm(A);
    X.signForm(B);
		Form C("Tom", 151,1);
		std::cout << "Tom is ok\n\n";
	}
	catch(std::exception &e){
    std::cerr << e.what();
  }
  std::cout << "-----------------------------------------------\n";
	try
	{
		Form D("JJ",1,10);
		std::cout << "!!!!!!!JJ is ok\n\n";
		Form E("MIKE", 0,1);
		std::cout << "!!!!!!!MIKE is ok\n\n";
	}
  catch(std:: exception &e){
    e.what();
  }
  std::cout << "-----------------------------------------------\n";
	try
	{
		Bureaucrat D("Dong",10);
		std::cout << "D is ok\n\n";
		Form X("XX",1,10);
    Form Z("ZZ",5,10);
		Bureaucrat Y("YY",2);
		Y.signForm(X);
    Y.signForm(Z);
    std::cout << D;
    std::cout << X;
	}
  catch (std:: exception &e){
    e.what();
  }
  std::cout << "-----------------------------------------------\n";
}
