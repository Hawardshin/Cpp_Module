#include "Convert.hpp"


Convert::Convert() :() {}

Convert::Convert(const Convert &obj) {
  std::cout <<"[Convert Copy constructor called]\n" <<"You make " << obj. << "\n\n";
}

Convert::~Convert() {}

Convert& Convert::operator=(const Convert& obj){
  return (*this);
}
