#pragma once
#include <exception>
#include <iostream>
//i think I need to think this leaks
template <typename T>
class Array
{
public:
	Array(){
		std::cout << "[Array Default constructor called]\n";
		len = 1;//is this ok?
		arr = new T[1];
	}
	explicit Array(const int n){
		std::cout << "[Array Param constructor called]\n";
		if (n < 0 )
			throw InvaildRange();
		arr = new T[n];
		len = n;
	}

	Array(const Array& obj ){
		std::cout << "[Array Copy constructor called]\n";
		len = obj.len;
		arr = new T[len];
		for (size_t i=0; i < len;i++) arr[i] = obj[i];
	}
	~Array() {
	std::cout << "[Array Destructor called]\n";
	delete[] arr;
	}
	Array& operator=(const Array& obj ){
		std::cout <<"[Array Copy assignment operator called]\n";
		delete[] arr;
		len = obj.len;
		arr = new T[len];
		for (size_t i=0; i < len;i++) arr[i] = obj[i];
		return (*this);
	}
	T &operator[](const int idx){
		if (idx < 0 || static_cast<size_t>(idx) >= len)
			throw InvaildRange();
		return (arr[idx]);
	}
	const T& operator[] (const int idx) const{
		if (idx < 0 || static_cast<size_t>(idx) >= len)
			throw InvaildRange();
		return (arr[idx]);
	}
	size_t size() const {
		return (len);
	}

private:
	T *arr;
	size_t len;
	class InvaildRange: public std::exception{
		virtual const char* what(void) const throw() { return ("idx range is invalid!!!\n"); }
	};

};
