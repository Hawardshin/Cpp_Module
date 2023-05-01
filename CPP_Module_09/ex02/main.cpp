# include "PmergeMe.hpp"


int main(int argc, char** argv){
  try
  {
    PmergeMe a(argc, argv);
    a.checkError();
    a.sortExecute();
    // a.checkSorted();
  }
  catch(std::exception& e){
    std::cout << e.what();
  }
}
