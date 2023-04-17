#ifndef SPAN_HPP
# define SPAN_HPP

# include <sstream>
# include <iostream>
# include <vector>
# include <stdexcept>
# include <string>
# include <climits>
# include <ctime>
class Span
{
public:
  explicit Span(const unsigned int& N);
  Span(const Span& obj);
  ~Span();
  Span& operator=(const Span& obj );
  void  addNumber(int a) throw (std::out_of_range);
  unsigned int  shortestSpan() throw(std::logic_error);
  unsigned int  longestSpan() throw (std::logic_error);
  void initNumberRange(unsigned int count) throw (std::out_of_range);
private:
  Span();
  void  checkStore() const throw (std::out_of_range);
  void  copyStorage(std::vector<int> &obj) const ;
  std::vector<int> storage;
  unsigned int maxSize;
  unsigned int nowSize;
};


#endif
