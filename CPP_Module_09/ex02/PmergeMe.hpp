#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>
# include <deque>
# include <cctype>
# include <exception>
# include <cstdlib>
class PmergeMe
{
public:
  static const int  THRESHOLDS;
  static const char* ERROR_MSG;
  PmergeMe(int argc, char **argv);
  PmergeMe(const PmergeMe& obj);
  ~PmergeMe();
  PmergeMe& operator=(const PmergeMe& obj );
  bool  isNum(const char *arr);
  void  sortExecute() throw(std::invalid_argument &);
  void  Mergesort();
  void  checkError() throw(std::invalid_argument &);
private:
  bool  checkOverFlow(long long ll);
  bool isError;
  PmergeMe();
  std::vector<int> myvec;
  std::deque<int> mydque;
};

#endif
