#include "Serializer.hpp"

int main(){
  Data d;
  d.a = 1;
  d.b = 2;
  uintptr_t test1;
  Data *test2;
  std::cout << "before : " << &d << "\n";
  test1 = Serializer::serialize(&d);
  std::cout << test1 << "\n";
  test2 =  Serializer::deserialize(test1);
  std::cout << "after  : "  << test2 << "\n";
  std::cout << test2->a <<" " <<test2->b << "\n";
}
