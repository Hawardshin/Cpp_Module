#include <iostream>
#include <string>
#include <map>
#include <cmath>
void  checkOverFlow(double d){
  int a = d;
  if (static_cast<double> (a) != std::floor(d))
    throw std::overflow_error("Error: too large a number.\n");
}

using namespace std;
int main()
{
	string a("abcd,");
	size_t pos = a.find(',');
	cout << pos << "\n";
	std::cout << a.substr(0,pos);
	std::cout << a.substr(pos+1);
	// std::cout << a.substr(a.size() + 1);

  checkOverFlow(1.11111111111111134287598425134789135679813456789123456978146589643895689712346781265827136589123659812365286897536187316289436128947678934759873412938120938111111);
  string s = "";
  double ret = std::atof(s.c_str());
  cout << ret << '\n';
}
