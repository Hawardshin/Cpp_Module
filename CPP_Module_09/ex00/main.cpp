# include "BitcoinExchange.hpp"
//TO DO
//error msg standard out put
//error test
int main(int argc, char *argv[]){
	BitcoinExchange test;
	try{
		test.initCsv(argc);
		test.coinToMoney(argv[1]);
	}catch(std::exception &e){
		std::cerr << e.what();
	}
  return (0);
}
