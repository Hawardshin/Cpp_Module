#include "PmergeMe.hpp"

const char* PmergeMe::ERROR_MSG = "Error\n";
const int PmergeMe::THRESHOLDS = 32;
bool PmergeMe::isNum(const char *arr){
  long long n = 0;
  if (!arr)
    return (0);
  int i =0;
  if (arr[0] == '+')
    i++;
  for (; arr[i]!= '\0' ; i++){
    std::cout << arr[i];
    if (!std::isdigit(arr[i]))
      return (0);
    n *=10;
    n += arr[i] - '0';
  }
  if (i > 11 || checkOverFlow(n))
    return (0);
  return (1);
}

PmergeMe::PmergeMe(int argc, char**argv){
  if (argc == 1)
    isError = true;
  else{
    for (int i=0; i + 1 < argc; i++){
      if (!isNum(argv[i+1]))
        isError = true;
      else {
        mydque.push_back(std::atoi(argv[i+1]));
        myvec.push_back(std::atoi(argv[i+1]));
      }
    }
  }
}

PmergeMe::PmergeMe(const PmergeMe &obj) {
  mydque = obj.mydque;
  myvec = obj.myvec;
}

PmergeMe::~PmergeMe() {
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj){
  mydque = obj.mydque;
  myvec = obj.myvec;
  return (*this);
}




void  sortExecute() throw(std::invalid_argument &){
  checkError();
  if ()
}
//private
void PmergeMe::checkError() throw(std::invalid_argument &){
  if (isError)
    throw(std::invalid_argument(ERROR_MSG));
}

bool  PmergeMe::checkOverFlow(long long ll){
  int a = ll;
  if (static_cast<long long> (a) != ll)
    return(true);
  return (false);
}

PmergeMe::PmergeMe() {
}
