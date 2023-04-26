# include "BitcoinExchange.hpp"
//TO DO
// 1. Error message Define
// 2.
int main(int argc, char *argv[]){
	BitcoinExchange test;
	try{
		test.initCsv(argc);
	}catch(std::exception &e){
		std::cerr << e.what();
	}

	(void) argv;
  return (0);
}
