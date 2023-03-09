#include "Base.hpp"

Base::~Base()
{
	std::cout << "A destructor called..\n";
}

// It randomly instanciates A, B or C and returns the instance as a Base pointer.
// Feel free to use anything you like for the random choice implementation.
Base* generate(void){
  srand((unsigned int)time(NULL));//for seed changed by time
  int generate_thing( std::rand() %3)//0~2 3things A|B|C
  switch(generate_thing)
  {
    case 0 : return (new A)
              break;
    case 1 :
              break;
    case 2 :
              break;
    case
  }

}
void identify(Base* p){

}

void identify(Base& p){

}
