#include "Array.hpp"
#include <cstdio> //size_t
#include <iostream>
int main()
{
	 int * a = new int();
	 std::cout << a <<"\n";
	 std::cout << *a <<"\n";
	 delete a;

	 try{
		Array<int> test1(10);
		std::cout << test1[1] << "\n";
		std::cout  << test1[100];
		std::cout <<"test1 ok\n";
	 }
	 catch(std::exception &e){
		std::cerr << e.what();
		}
		try{
			Array <int> test2(-1);
			std::cout << "test2 ok\n";
		}
		catch (std::exception &e){
			std::cerr << e.what() << "\n";
		}
		try{
			Array <std::string> test3(5) ;
			Array<std::string> s(test3);
			std::cout << "test3 ok\n";
		}
		catch(std::exception &e){
			std::cerr << e.what() << "\n";
		}
}
