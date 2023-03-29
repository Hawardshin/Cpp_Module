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
	explicit Array(const int n){
		arr = new T[n];
		len = n;
	}
	Array(const Array& obj ){
		len = obj.len;
		arr = new T[len];
		for (size_t i=0; i < len;i++) arr[i] = obj[i];
	}
	~Array() { delete arr; }
	Array& operator=(const Array& obj ){
		delete arr;
		len = obj.len;
		arr = new T[len];
		for (size_t i=0; i < len;i++) arr[i] = obj[i];
		return (*this);
	}
	T &operator[](const int idx){
		if (idx < 0 || static_cast<size_t>(idx) > len)
			throw IndexOutOfRange();
		return (arr[idx]);
	}
	const T& operator[] (const int idx) const{
		if (idx < 0 || static_cast<size_t>(idx) > len)
			throw IndexOutOfRange();
		return (arr[idx])
	}
	const size_t size() const {
		return (len);
	}

private:
	T *arr;
	size_t len;
	class IndexOutOfRange: public std::exception{
		virtual const char* what(void) const throw() { return ("idx range is invalid!!!\n"); }
	};

};
