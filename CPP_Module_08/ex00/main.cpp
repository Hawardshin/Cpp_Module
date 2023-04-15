#include "easyfind.hpp"

int main(void) {
  std::list<int> my_list;
  std::vector<int> my_vec;
  std::deque<int> my_deque;
  for(int i=0;i < 10; i++){
    my_list.push_back(i*10);
    my_vec.push_back(10);
    my_deque.push_back(i*10);
  }
  int to_find = 50;
  try {//find check
    std::deque<int>::iterator iter = easyfind(my_deque, to_find);
    std::cout << "Value " << *iter << " found on Index "<< std::distance(my_deque.begin(), iter) << "\n";
    std::cout << "Next thing is " << *++iter << "\n";
  } catch (std::exception& e) {
    std::cerr << e.what() << "\n";
  }
  to_find = -1;
  try{//cannot find;
    std::list<int>::iterator iter = easyfind(my_list,to_find);
    std::cout << *iter << "\n";
  }catch(std::exception& e){
    std::cerr << e.what()<< "\n";
  }
  to_find = 10;
  try{//cannot find;
    std::vector<int>::iterator iter = easyfind(my_vec,to_find);
    std::cout << "Value " << *iter << " found on Index "<< std::distance(my_vec.begin(), iter) << "\n";
  }catch(std::exception& e){
    std::cerr << e.what()<< "\n";
  }
}
