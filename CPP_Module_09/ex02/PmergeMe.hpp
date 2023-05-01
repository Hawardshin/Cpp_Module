#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>
# include <deque>
# include <cctype>
# include <exception>
# include <cstdlib>
# include <ctime>
# include <iomanip>
class PmergeMe
{
public:
  static const int  THRESHOLDS;
  static const char* ERROR_MSG;
  PmergeMe(int argc, char **argv);
  PmergeMe(const PmergeMe& obj);
  ~PmergeMe();
  PmergeMe& operator=(const PmergeMe& obj );
  void  sortExecute() throw(std::invalid_argument &);
  void  checkError() throw(std::invalid_argument &);
  void  checkSorted();

private:
  PmergeMe();
  bool  isNum(const char *arr);
  bool  checkOverFlow(long long ll);
  void  printEachTime();
  bool isError;
  int mysize;
  double _vectorTime;
	double _dequeTime;
  std::vector<int> myvec;
  std::deque<int> mydque;

public :
  template <typename T>
  void  Insertsort(T& A){
    int n = A.size();
    for (int i=1; i < n;i++){
      int value = A[i];
      int hole = i;
      //하나씩 뒤로 밀기
      while (hole > 0 && A[hole - 1] > value){
        A[hole] = A[hole -1];
        hole--;
      }
      A[hole] = value;
    }
  }

  template<typename T>
  void  Merge(T& L, T& R, T &A){
    int nL = L.size();
    int nR = R.size();
    int i = 0;// L에서 가장작고 아직 선택되지 않은 인덱스
    int j = 0;// R에서 가장작고 아직 선택되지 않은 인덱스
    int k = 0; // 정렬된 배열의 인덱스
    while (i < nL && j < nR){
      if (L[i] <= R[j])
        A[k++] = L[i++];
      else
        A[k++] = R[j++];
    }
    //한쪽 배열이 이미 다 사용 되면 남은 배열은 그 뒤로 정렬된다.
    while (i < nL){
      A[k++] = L[i++];
    }
    while (j < nR){
      A[k++] = R[j++];
    }
  }

//결과 값이 A 배열에 업데이트 된다.
  template <typename T>
  void  Mergesort(T& A){
    int n = A.size();
    if (n < 2)
      return;
    if (n > THRESHOLDS)
    {
      int mid = n / 2;
      T left(mid);
      T right(n - mid);
      //들어 온 값을 반으로 쪼갠다.
      for (int i=0; i < mid;i++) {
        left[i] = A[i];
      }
      for (int i=mid; i < n; i ++){
        right[i - mid] = A[i];
      }
      Mergesort(left);
      Mergesort(right);
      Merge(left, right, A);
    }
    else{
      Insertsort(A);
    }
  }

  template <typename T>
  void  printAllValue(T& A){
    for (size_t i=0;i < A.size();i++){
      std::cout << A[i] << " ";
    }
    std::cout << "\n";
  }
};

#endif
