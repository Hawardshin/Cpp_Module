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
		std::cout << "size : " << test1.size() << "\n";
		test1[1] = 1;
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
			for (int i=0; i < 5;i++) test3[i] = "hi";
			Array<std::string> test3_copy(test3);
			for (int i=0;i < 5;i++) std::cout << test3[i] << " ";
			std::cout <<"\n";
			for (int i=0;i < 5;i++) std::cout <<test3_copy[i] << " ";
			std::cout << "\n";
			std::cout << "\n-----------------change-------------------\n\n";
			for(int i=0;i < 5;i++) test3_copy[i] = "hello";
			for (int i=0;i < 5;i++) std::cout << test3[i] << " ";
			std::cout <<"\n";
			for (int i=0;i < 5;i++) std::cout <<test3_copy[i] << " ";
			std::cout << "\n";
			std::cout << "\n-----------------Copy assignment operator-------------------\n\n";
			test3 = test3_copy;
			for (int i=0;i < 5;i++) std::cout << test3[i] << " ";
			std::cout <<"\n";
			for (int i=0;i < 5;i++) std::cout <<test3_copy[i] << " ";
			std::cout << "\n";
			std::cout << "test3 ok\n";
		}
		catch(std::exception &e){
			std::cerr << e.what() << "\n";
		}
}
