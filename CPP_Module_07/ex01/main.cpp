#include "iter.hpp"

int main()
{
  int test1_array[5] = {1,2,3,4,5};
  char test2_array[5] = {'a','b','c','d','e'};
  std::string test3_array[5]={"hi","my name", "is joushin", "thank you", "so much"};
  ::iter(test1_array, 5, test_fuc<int>);
  ::iter(test2_array, 5, test_fuc<char>);
  ::iter(test3_array, 5, test_fuc<std::string>);
  ::iter(test3_array, 5, test_fuc);
}
