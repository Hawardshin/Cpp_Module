# include "PmergeMe.hpp"


int main(int argc, char** argv){
  try
  {
    PmergeMe a(argc, argv);
    a.checkError();
    a.sortExecute();
  }
  catch(std::exception& e){
    std::cout << e.what();
  }
}
