
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << "-------------test 1--------------\n\n";
		Animal a;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
		std::cout << "-------------test 1 done---------\n\n";
	}
	{
		std::cout << "-------------test 2--------------\n\n";
		Animal *ani[6];
		//In your main function, create and fill an array of Animal objects.
		//Half of it will be Dog objects and the other half will be Cat objects.
		std::cout << "--------------Dog make --------------\n\n";
		for (int i=0;i < 3;i++) ani[i] = new Dog();
		std::cout << "--------------Cat make --------------\n\n";
		for (int j=3;j < 6;j++) ani[j] = new Cat();
		// At the end of your program execution, loop over this array and delete every Animal.
		//You must delete directly dogs and cats as Animals.
		//The appropriate destructors must be called in the expected order.
		std::cout << "--------------Delete Animal----------\n\n";
		for (int i=0; i <6;i++) delete ani[i];
		std::cout << "-------------test 2 done---------\n\n";
	}
	{//deep copy
		std::cout << "-------------test 3--------------\n\n";
		std::string string_arr[100];
		for (int i=0; i< 100;i++) string_arr[i] = "hi";
		Brain *brain_arr = new Brain(string_arr);
		Cat A(brain_arr);
		Cat B(A);
		Cat C= A;
		//shallow copy is if (I change brain_arr that effect other class)
		std::cout << "\n\n-----------first see---------------\n\n";
		std::cout << "\n-----------A--------------\n";
		A.see_brain();
		std::cout << "\n-----------B--------------\n";
		B.see_brain();
		std::cout << "\n-----------C--------------\n";
		C.see_brain();
		std::cout << "\n\n-----------Second see---------------\n\n";
		for (int i=0; i< 100;i++) string_arr[i] = "hello";
		Brain	*brain_tmp = brain_arr;
		brain_arr = new Brain(string_arr);
		std::cout << "\n-----------A--------------\n";
		A.see_brain();
		std::cout << "\n-----------B--------------\n";
		B.see_brain();
		std::cout << "\n-----------C--------------\n";
		C.see_brain();
		delete brain_arr;
		delete brain_tmp;
		std::cout << "-------------test 3 done---------\n\n";
	}
	//Don’t forget to check for memory leaks.
	//system("leaks Animal");
	system("leaks Animal");
}
