#include <ctime>
#include <cstdlib>
#include <typeinfo>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
Base* generate(void){
  srand((unsigned int)time(NULL));//for seed changed by time
  int generate_thing( std::rand() %3);//0~2 3things A|B|C
  Base *base_p(NULL);
  switch(generate_thing){
    case 0 :base_p =  new A;
              break;
    case 1 : base_p = new B;
              break;
    case 2 :base_p = new C;
              break;
  }
  return (base_p);
}

void identify(Base* p){
  A* a1 = dynamic_cast<A*> (p);
  B* b1 = dynamic_cast<B*> (p);
  C* c1 = dynamic_cast<C*> (p);

  if (a1)
    std::cout << "[pointer] actual type of the object point is A\n";
  else if (b1)
    std::cout << "[pointer] actual type of the object point is B\n";
  else if (c1)
    std::cout << "[pointer] actual type of the object point is C\n";
  else
    std::cout << "[pointer] actual type of the object point is Base\n";
}

void identify(Base& p){
  try{
    A& atmp = dynamic_cast<A&> (p);
    static_cast<void>(atmp);
    std::cout << "[ref] actual type of the object point is A\n";
  }
  catch( const std :: bad_cast &e ) {}
  try{
    B& btmp = dynamic_cast<B&>(p);
    static_cast<void>(btmp);
    std::cout << "[ref] actual type of the object point is B\n";
  }
  catch( const std :: bad_cast &e ) {}
  try{
    C& ctmp =  dynamic_cast<C&>(p);
    static_cast<void>(ctmp);
    std::cout << "[ref] actual type of the object point is C\n";
  }
  catch( const std :: bad_cast &e ) {}
  std::cout << "[ref] actual type of the object point is Base\n";
}

int main(){
  Base base;
	Base* my_base = new Base;
	Base* random_type;

	random_type = generate();
	identify(my_base);
	identify(*my_base);
  std::cout << "==============random===============\n";
	identify(random_type);
	identify(*random_type);
	delete random_type;
  std::cout << "-------------done-----------------\n";
	return (0);
}
