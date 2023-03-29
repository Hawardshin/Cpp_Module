#pragma once
#include <exception>
#include <iostream>
//i think I need to think this leaks
template <typename T>
class Array
{
public:
	Array(){
		len = 1;//is this ok?
		arr = new T[1];
	}
	explicit Array(unsigned int n){
		arr = new T[n];
		len = n;
	}
	Array(const Array& obj ){
		len = obj.len;
		arr = new T[len];
		for (unsigned int i=0; i < len;i++){
			arr[i] = obj[i];
		}
	}
	~Array(){
		delete arr;
	}
	Array& operator=(const Array& obj ){
		delete arr;
		len = obj.len;
		arr = new T[len];
		for (unsigned int i=0; i < len;i++){
			arr[i] = obj[i];
		}
		return (*this);
	}
	T &operator[](const int idx){
		if (idx < 0 || static_cast<unsigned int>(idx) > len) // is this ok?
		{
			std::cerr << "idx range is invalid!!!\n";
			return (-1);
		}
	const T& operator[] (std::size_t i) const;

	}

private:
	T *arr;
	unsigned int len;
	class IndexOutOfRange: public std::exception{
		virtual const char* what(void) const throw();
	};

};
