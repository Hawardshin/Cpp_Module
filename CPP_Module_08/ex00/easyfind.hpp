#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <sstream>
#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <vector>
#include <stdexcept>
#include <algorithm>

// 모든 컨테이너는 begin(), end() 함수를 가진다.
template <typename T>
typename T::iterator easyfind(T &toFind , int value){
  typename T::iterator iter = std::find(toFind.begin(), toFind.end(),value);
  std::ostringstream oss;
  oss << value;
  if (iter == toFind.end())
    throw std::runtime_error(std::string("Value : ")+ oss.str() + std::string(" is not in this container"));
  return (iter);
}

#endif
