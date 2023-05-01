#include "PmergeMe.hpp"

const char* PmergeMe::ERROR_MSG = "Error\n";
const int PmergeMe::THRESHOLDS = 32;

PmergeMe::PmergeMe(int argc, char**argv){
  mysize = argc - 1;
  isError = false;
  _vectorTime = 0;
  _dequeTime = 0;
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
  isError = obj.isError;
  mysize= obj.mysize;
  _vectorTime = obj._vectorTime;
  _dequeTime = obj._dequeTime;
}

PmergeMe::~PmergeMe() {
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj){
  mydque = obj.mydque;
  myvec = obj.myvec;
  isError = obj.isError;
  mysize= obj.mysize;
  _vectorTime = obj._vectorTime;
  _dequeTime = obj._dequeTime;
  return (*this);
}

void  PmergeMe::sortExecute() throw(std::invalid_argument &){
  checkError();
  std::cout << "Before: ";
  printAllValue(myvec);
  std::clock_t c_start = std::clock();
  Mergesort(myvec);
  std::clock_t c_finish = std::clock();
  _vectorTime = static_cast<double>(c_finish - c_start) * 1000/CLOCKS_PER_SEC;//ms
  std::cout << "After: ";
  printAllValue(myvec);
  c_start = std::clock();
  Mergesort(mydque);
  c_finish = std::clock();
  _dequeTime = static_cast<double>(c_finish - c_start) * 1000/CLOCKS_PER_SEC;//ms
  printEachTime();
}

void PmergeMe::checkError() throw(std::invalid_argument &){
  if (isError)
    throw(std::invalid_argument(ERROR_MSG));
}

void  PmergeMe::checkSorted(){
  std::vector<int>vt1 = myvec;
  std::deque<int>dt1 = mydque;
  std::sort(vt1.begin(),vt1.end());
  std::sort(dt1.begin(),dt1.end());
  if (vt1 == myvec)
    std::cout << "Well Done vector\n";
  if (dt1 == mydque)
     std::cout << "Well Done dque\n";
}

//private
PmergeMe::PmergeMe() {}

bool PmergeMe::isNum(const char *arr){
  long long n = 0;
  if (!arr)
    return (0);
  int i =0;
  if (arr[0] == '+')
    i++;
  for (; arr[i]!= '\0' ; i++){
    // std::cout << arr[i];
    if (!std::isdigit(arr[i]))
      return (0);
    n *=10;
    n += arr[i] - '0';
  }
  if ((i == 1 && arr[0] == '+')|| i > 11 || checkOverFlow(n))
    return (0);
  return (1);
}

bool  PmergeMe::checkOverFlow(long long ll){
  int a = ll;
  if (static_cast<long long> (a) != ll)
    return(true);
  return (false);
}

void  PmergeMe::printEachTime(){
 std::cout << "Time to process a range of " << std::setw(5) << mysize
			  << " elements with std::vector : " << std::setw(8) << _vectorTime
			  << " ms\n";
	std::cout << "Time to process a range of " << std::setw(5) << mysize
			  << " elements with std::deque : " << std::setw(8) << _dequeTime
			  << " ms\n";
}
