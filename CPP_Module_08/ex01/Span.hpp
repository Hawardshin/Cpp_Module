#ifndef SPAN_HPP
# define SPAN_HPP

class Span
{
public:
  explicit Span(const unsigned int& N);
  Span(const Span& obj );
  ~Span();
  Span& operator=(const Span& obj );
  void  addNumber();
private:
  Span();
  unsigned int max_size;
  unsigned int now_size;
};


#endif
