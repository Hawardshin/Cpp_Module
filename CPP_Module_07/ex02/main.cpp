#include "Array.hpp"
#include <iostream>
int main()
{
	 int * a = new int();
	 std::cout << a <<"\n";
	 std::cout << *a <<"\n";
	 delete a;
}
