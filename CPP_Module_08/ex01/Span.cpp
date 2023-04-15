#include "Span.hpp"


Span::Span(const unsigned int &N) :max_size(N) ,now_size(0){
  std::cout <<"[Span parameter constructor called]\n" << "\n\n";
}

Span::Span(const Span &obj) {
  std::cout <<"[Span Copy constructor called]\n" <<"You make " <<"\n\n";
}

Span::~Span() {
  std::cout <<"[Span Destructor called]\n" <<"extinguish " << "\n\n";
}

Span& Span::operator=(const Span& obj){
  std::cout <<"[Span Copy assignment operator called]\n\n"
  return (*this);
}

Span::Span() {
  std::cout <<"[Span Default constructor called]\n\n" ;
}
