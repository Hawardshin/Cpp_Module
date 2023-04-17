#include "Span.hpp"

//public
Span::Span(const unsigned int &N) :maxSize(N) ,nowSize(0){
  std::cout <<"[Span parameter constructor called]\n" ;
}

Span::Span(const Span &obj) {
  obj.copyStorage(storage);
  std::cout <<"[Span Copy constructor called]\n";
}

Span::~Span() {
  std::cout <<"[Span Destructor called]\n";
}

Span& Span::operator=(const Span& obj){
  maxSize = obj.maxSize;
  nowSize = obj.nowSize;
  std::cout <<"[Span Copy assignment operator called]\n";
  storage = obj.storage;
  return (*this);
}

void Span:: addNumber(int a) throw(std::out_of_range){
  checkStore();
  nowSize++;
  storage.push_back(a);
}

unsigned int Span:: shortestSpan() throw(std::logic_error){
  if (nowSize <= 1)
    throw std::logic_error("There are not enough numbers in the data structure.");
  sort(storage.begin(), storage.end());
  unsigned int ret = std::numeric_limits<unsigned int>::max();
  for (std::vector<int>::iterator it = storage.begin(); it + 1 != storage.end(); it++){
    if (static_cast<unsigned int>(*(it + 1) - *it) < ret)
        ret = *(it + 1) - *it;
  }
  return (ret);
}

unsigned int Span::longestSpan()throw (std::logic_error){
  if (nowSize <= 1)
    throw std::logic_error("There are not enough numbers in the data structure.");
  std::sort(storage.begin(), storage.end());
  return (storage[nowSize -1] - storage[0]);
}

unsigned int getRandomNumber(){
	return (std::rand() % std::numeric_limits<int>::max());
}

void Span::initNumberRange(unsigned int count)throw (std::out_of_range){
  std::ostringstream oss;
  if (count > maxSize)
		throw std::out_of_range("!!!Max size is " + oss.str());
	std::vector<int>::iterator start;
	srand(time(NULL));
	storage.resize(count);
  nowSize = count;
	std::generate(storage.begin(), storage.end(), getRandomNumber);
}

//private
Span::Span() {
  std::cout <<"[Span Default constructor called]\n\n" ;
}

void  Span::checkStore()const throw (std::out_of_range){
  if (nowSize >= maxSize){
    std::ostringstream oss;
    oss << maxSize;
    throw std::out_of_range("!!!Max size is " + oss.str());
  }
}

void  Span::copyStorage(std::vector<int> &obj) const{
  for(unsigned int i=0; i < obj.size();i++){
    obj.push_back(storage[i]);
  }
}
