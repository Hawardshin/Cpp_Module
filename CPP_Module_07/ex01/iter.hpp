#pragma once
#include <iostream>

template <typename T1, typename T2>
void  iter(T1 *array, unsigned int len, T2 fucptr)
{
  for (unsigned int i=0;i < len;i++) fucptr(array[i]);
}


template <typename T>
void  test_fuc(const T& a){
  std::cout << "=============start test fuc ===============\n" \
  << " value : " << a << "\n=============end test fuc =================\n";
}

