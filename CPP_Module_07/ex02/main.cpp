
#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
		std::cout << "\n\n----------------intra test done------------------------\n\n";
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
	return 0;
}
